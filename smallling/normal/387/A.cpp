#include<cstdio>
#include<cstdlib>
using namespace std;
int xs,xs1,fz,fz1,xs2,fz2;
char ch,ch1;
int main()
{
    scanf("%c%c",&ch,&ch1);
    xs=(ch-'0')*10+(ch1-'0')*1;
    scanf("%c",&ch);
    scanf("%c%c\n",&ch,&ch1);
    fz=(ch-'0')*10+(ch1-'0')*1;
    scanf("%c%c",&ch,&ch1);
    xs1=(ch-'0')*10+(ch1-'0')*1;
    scanf("%c",&ch);
    scanf("%c%c",&ch,&ch1);
    fz1=(ch-'0')*10+(ch1-'0')*1;
    if(fz>=fz1)fz2=fz-fz1;
    else{fz2=fz+60-fz1;xs--;}
    if(xs>=xs1)xs2=xs-xs1;
    else xs2=xs+24-xs1;
    if(xs2<10)printf("0");
    printf("%d:",xs2);
    if(fz2<10)printf("0");
    printf("%d",fz2);
}