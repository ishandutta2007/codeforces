#include<iostream>
#include<stdio.h>
using namespace std;
int main()
    {
    int r1,r2,c1,c2,d1,d2;
    scanf("%d%d%d%d%d%d",&r1,&r2,&c1,&c2,&d1,&d2);
    int a,b,c,d;
    for(a=1;a<=9;a++)
        {
        for(b=1;b<=9;b++)
            {
            for(c=1;c<=9;c++)
                {
                for(d=1;d<=9;d++)
                    {
                    if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
                        {
                        if(r1==a+b && r2==c+d && c1==a+c && c2==b+d && d1==a+d && d2==b+c)
                            {
                            printf("%d %d\n%d %d",a,b,c,d);
                            return 0;
                            }
                        }
                    }
                }
            }
        }
    printf("-1");
    return 0;
    }