#include<stdio.h>
int main(){
int a,b,c,d;
scanf("%d%d%d%d",&a,&b,&c,&d);
int e=a^b,f=c|d,g=b&c,h=a^d,i=e&f,j=g|h,k=i^j;
printf("%d\n",k);
return 0;
}