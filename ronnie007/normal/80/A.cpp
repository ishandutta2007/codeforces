#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,m;
    scanf("%d%d",&n,&m);
    int p[20];
    p[0]=2;
    p[1]=3;
    p[2]=5;
    p[3]=7;
    p[4]=11;
    p[5]=13;
    p[6]=17;
    p[7]=19;
    p[8]=23;
    p[9]=29;
    p[10]=31;
    p[11]=37;
    p[12]=41;
    p[13]=43;
    p[14]=47;
    p[15]=-1;
    int i;
    for(i=0;i<15;i++)
        {
        if(p[i]==n)
            {
            if(p[i+1]==m)
                {
                printf("YES\n");
                return 0;
                }
            else {printf("NO\n");return 0;}
            }
        }
    return 0;
    }