#include<stdio.h>
#include<cstring>
using namespace std;
int a1,a2,a3,a4;
int main()
{
    scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
    int len=(a1+a2);
    if((a3>a4+1||a4>a3+1)||(a1<a3||a1<a4||a2<a4||a2<a3))
    {
                        printf("-1\n");
                        return 0;
                        }
    if(a3==a4)
    {
              if(a1==a3)
              {
                        if(a1==a2){printf("-1\n");return 0;}
                        for(int i=1;i<=a3;i++)putchar('7'),putchar('4');
                        putchar('7');for(int i=1;i<=a2-a1-1;i++)putchar('7');
                        //for(;;);
                        return 0;
                        }
              for(int i=1;i<=a1-a3;i++)putchar('4');
              for(int i=1;i<a3;i++)
              putchar('7'),putchar('4');
              for(int i=1;i<=a2-a3+1;i++)putchar('7');
              putchar('4');
              }
    else
    if(a3==a4+1)
    {
                //if(a1==a4||a2==a4){printf("-1\n");return 0;}
                for(int i=1;i<=a1-a4;i++)putchar('4');
                for(int i=1;i<=a4;i++)putchar('7'),putchar('4');
                for(int i=1;i<=a2-a4;i++)putchar('7');
                }
    else
    if(a3+1==a4)
    {
              //if(a1==a3||a2==a3){printf("-1\n");return 0;}
              putchar('7');
              for(int i=1;i<=a1-a3;i++)putchar('4');
              for(int i=1;i<a3;i++)
              putchar('7'),putchar('4');
              for(int i=1;i<=a2-a3;i++)putchar('7');
              putchar('4');
              }
    return 0;
}