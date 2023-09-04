#include<stdio.h>
#include<stdlib.h>
/*
MANISHIMWE ERIC 24623
SHEMA ROGER 24588
UMUHOZA FRANCOISE 23680
ISHIMWE ADERINE   24632
*/
////////////The datatype of car_plate_number is integer //////////////////////////////
struct car{
int car_plate_number;
char car_name[20];
int client_phone_number;
char date[12];
int price;
};

int main(){
int choice;

 	do
 	{
 printf("\n\n\n");
    printf("\t\t\t######################################################################\n");
    printf("\t\t\t#                                                                    #\n");
    printf("\t\t\t#                                                                    #\n");
    printf("\t\t\t#                WELCOME TO CARWASH MANAGEMENT SYSTEM                #\n");
    printf("\t\t\t#                                                                    #\n");
    printf("\t\t\t#                                                                    #\n");
    printf("\t\t\t######################################################################\n");
    printf("\n\n");
        printf("\t\t\t\t\tPRESS:...");
        printf("\n\n\t\t\t\t\t[1] RECORD NEW-CAR");
        printf("\n\t\t\t\t\t[2] DISPLAY-CARS");
        printf("\n\t\t\t\t\t[3] UPDATE-CAR");
        printf("\n\t\t\t\t\t[4] DELETE-CAR");
        printf("\n\t\t\t\t\t[5] SORT-CAR");
        printf("\n\t\t\t\t\t[6] SEARCH-CAR");
        printf("\n\t\t\t\t\t[0] EXIT");
        printf("\n\n\n\t\t\t\t\tMake a choice:");
        scanf("%d",&choice);
 	        switch (choice){
             case 1:
            system("cls");
            record_newcar();
            system("cls");
            break;
        case 2:
            system("cls");
            display_car();
             printf("\n\n\t\t\t\t press any key to Exist\n");
            getch();
            system("cls");
            break;
        case 3:
            system("cls");
            update_car();
            system("cls");
            break;
        case 4:
            system("cls");
             delete_car();
            system("cls");
            break;
        case 5:
               system("cls");
               sort_car();
               system("cls");
                break;
        case 6:
            system("cls");
              search_car();
             system("cls");
              break;
             case 0:
            printf("\n\n\t\t\t\t\tSystem is closed");
            break;
        default:
            printf("\n\n\t\t\t\t\tChoice not found Try other choice\n");
            return;
        }

}while(choice!=0);

getch();
}
void record_newcar(){
 char ana;
     do{


    FILE *p;
    struct car R;
     p=fopen("car.txt","a");
       system("cls");
    printf("\t\t\t\t       RECORD-NEW-CAR\n");
    printf("\t\t\t\t   _____________________\n\n\n");
    printf("\t\t\t\tEnter Car_plate_number : ");
    scanf("%d",&R.car_plate_number);
    printf("\t\t\t\tEnter Car_name : ");
    scanf("%s",R.car_name);
    printf("\t\t\t\tEnter client_phone_number : ");
    scanf("%d",&R.client_phone_number);
    printf("\t\t\t\tDate : ");
    scanf("%s",R.date);
    printf("\t\t\t\tEnter Price_of_car : ");
    scanf("%d",&R.price);

    fprintf(p,"%d\t%s\t%d\t%s\t%d\n",R.car_plate_number,R.car_name,R.client_phone_number,R.date,R.price);
    fclose(p);
    printf("\n\n\t\t\t\t _________________________________\n");
     printf("\t\t\t\t Car record successful\n");
    printf("\t\t\t\t Do you want to Add another record y/n :");
                  scanf("%s",&ana);

   }while(ana=='y'||ana=='Y');

}
void display_car(){

   FILE *p;
    struct car R;
     p=fopen("car.txt","r");
    system("cls");
    printf("\t\t\t\t       LIST-OF-CAR\n");
    printf("\t\t\t\t   _____________________\n\n\n");
   printf("\t\tPlate_number\tCare_name\tClient_phone\tWash_date\tPrice\n");
   while(!feof(p)){

   fscanf(p,"\t\t%d\t\t%s\t\t%d\t%s\t%d\n",&R.car_plate_number,R.car_name,&R.client_phone_number,R.date,&R.price);
   printf("\t\t%d\t\t%s\t\t%d\t%s\t%d\n",R.car_plate_number,R.car_name,R.client_phone_number,R.date,R.price);

    }
    fclose(p);
    getch();
}
///////////////////////////////////////search function/////////////////////////////
void search_car(){

  int sech;
  int found=0;
   FILE *p;
    struct car R;
     p=fopen("car.txt","r");
      system("cls");
    printf("\t\t\t======================DETAIL OF A CAR =============\n");
    printf("\t\t\t\t   _________________________________\n\n\n");
    printf("\t\t\t\t Enter Car-Plate-Number to search :..");
    scanf("%d",&sech);

      while(!feof(p)){
            fscanf(p,"\t\t%d\t\t%s\t\t%d\t%s\t%d\n",&R.car_plate_number,R.car_name,&R.client_phone_number,R.date,&R.price);
            if(R.car_plate_number==sech){
                    found=1;
        printf("\n\n\t\tPlate_number\tCare_name\tClient_phone\tWash_date\tPrice\n");
        printf("\t\t%d\t\t%s\t\t%d\t%s\t%d\n",R.car_plate_number,R.car_name,R.client_phone_number,R.date,R.price);


            }
      }
      if(!found){
        printf("\t\t\t Invalid a car_plate_number!!!!");

      }


     fclose(p);
      getch();
}


/////////////////////////////////////////////////////////////delete/////////////////////////////////


void delete_car(){
  int found=0,del;
   FILE *p,*pp;
    struct car R;
     p=fopen("car.txt","r");
     pp=fopen("delete.txt","w");
      system("cls");
    printf("\t\t\t======================DELETE A CAR==============\n");
    printf("\t\t\t\t   _________________________________\n\n\n");
    printf("\t\t\t Enter Car-Plate-Number you want to delete:..");
    scanf("%d",&del);

      while(!feof(p)){
            fscanf(p,"%d\t\t%s\t\t%d\t%s\t%d\n",&R.car_plate_number,R.car_name,&R.client_phone_number,R.date,&R.price);
            if(R.car_plate_number==del){
                    found=1;
            }else{

        fprintf(pp,"%d\t%s\t%d\t%s\t%d\n",R.car_plate_number,R.car_name,R.client_phone_number,R.date,R.price);


            }
            }
      if(found){
           fclose(p);
           fclose(pp);
           remove("car.txt");
           rename("delete.txt","car.txt");
        printf("\n\t\t\t Record deleted successful!!!!!");
		 }else{
        printf("\n\n\t\t\t\t Car Plate number not found\n\n");
	 }
      getch();
}

////////////////////////////////update//////////////////////////////////////////////
void update_car(){
  int found=0,upd;
   FILE *p,*pp,*ppp;
    struct car R;
     p=fopen("car.txt","r");
     pp=fopen("update.txt","w");
      system("cls");
    printf("\t\t\t======================UPDATE A CAR==============\n");
    printf("\t\t\t\t   _________________________________\n\n\n");
    printf("\t\t\t Enter Car-Plate-Number you want to Update:..");
    scanf("%d",&upd);
    while(!feof(p)){
            fscanf(p,"%d\t\t%s\t\t%d\t%s\t%d\n",&R.car_plate_number,R.car_name,&R.client_phone_number,R.date,&R.price);
            if(R.car_plate_number!=upd){
           fprintf(pp,"%d\t%s\t%d\t%s\t%d\n",R.car_plate_number,R.car_name,R.client_phone_number,R.date,R.price);
            }else{
            found=1;
             printf("\t\t\t\t =====DATA  BEFORE APDATE ========");
        printf("\n\n\t\tPlate_number\tCare_name\tClient_phone\tWash_date\tPrice\n");
        printf("\t\t%d\t\t%s\t\t%d\t%s\t%d\n",R.car_plate_number,R.car_name,R.client_phone_number,R.date,R.price);
            }
      }
      fclose(p);
      fclose(pp);
      if(found==1){
	 pp=fopen("update.txt","r");
	 p=fopen("car.txt","w");
      while(!feof(pp))
	 {
	 	fscanf(pp,"%d\t\t%s\t\t%d\t%s\t%d\n",&R.car_plate_number,R.car_name,&R.client_phone_number,R.date,&R.price);
		fprintf(p,"%d\t%s\t%d\t%s\t%d\n",R.car_plate_number,R.car_name,R.client_phone_number,R.date,R.price);
		 }
		 fclose(p);
		 fclose(pp);
		 	 }
    p=fopen("car.txt","a");
    printf("\n\n\t\t\t\t   ============UPDATED-CAR-FORM-CAR========\n");
    printf("\t\t\t\t   _____________________\n\n\n");
    printf("\t\t\t\tEnter Car_plate_number : ");
    scanf("%d",&R.car_plate_number);
    printf("\t\t\t\tEnter Car_name : ");
    scanf("%s",R.car_name);
    printf("\t\t\t\tEnter client_phone_number : ");
    scanf("%d",&R.client_phone_number);
    printf("\t\t\t\tDate : ");
    scanf("%s",R.date);
    printf("\t\t\t\tEnter Price_of_car : ");
    scanf("%d",&R.price);

    fprintf(p,"%d\t%s\t%d\t%s\t%d\n",R.car_plate_number,R.car_name,R.client_phone_number,R.date,R.price);

    printf("\n\n\t\t\t\t _________________________________\n");
     printf("\t\t\t\t Car Updated successful\n");
     fclose(p);
     getch();
      }
      /////////////////////////////////////////////////sort////////////////////////////////////////////


void sort_car(){
    int i,j,c=0,min,max;
 	struct car R[100],temp;
 	FILE *p;
   p=fopen("car.txt","r");
 	while(!feof(p))
 	{
    fscanf(p,"%d\t\t%s\t\t%d\t%s\t%d\n",&R[c].car_plate_number,R[c].car_name,&R[c].client_phone_number,R[c].date,&R[c].price);
    c++;

	 }

	 for(i=0;i<c-1;i++)
	 {

	 	min=R[i].car_plate_number;
	 	max=i;
	 	for(j=i+1;j<c;j++){
	 		if (R[j].car_plate_number<min)
	 		{
	 			min=R[j].car_plate_number;
	 			max=j;
			 }
		 }
		 temp=R[i];
		 R[i]=R[max];
		 R[max]=temp;
	 }
    printf("\n\n\t\t\t\t============LIST-AFTER-SORT-CAR========\n");
    printf("\t\t\t\t   ___________________________________\n\n\n");
    printf("\n\n\t\t\tPlate_number\tCare_name\tClient_phone\tWash_date\tPrice\n");
    for (i=0;i<c;i++){
    printf("\t\t\t%d\t\t%s\t\t%d\t%s\t%d\n",R[i].car_plate_number,R[i].car_name,R[i].client_phone_number,R[i].date,R[i].price);
     fclose(p);
	 }

getch();
 }
/////////////////////////////////////////////END OF PROJECT/////////////////////////////





