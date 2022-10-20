#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;


int a[5][5];
int s=0;

void input();
void solve();


int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    int s;
    int i,j;
    for(i=0;i<3;i++)
        {
        for(j=0;j<3;j++)
            {
            scanf("%d",&a[i][j]);
            }
        }
    s=a[0][1]+a[0][2];
    s++;
    //printf("%d\n",s);
    }


void solve()
    {
    int i,j,k=s;
    int sum;
    int sum1[10];
    int fl=0;
    for(k=s;k<=1000000;k++)
        {
        //printf("%d\n",k);
        a[0][0]=k-a[0][1]-a[0][2];
        a[1][1]=k-a[1][0]-a[1][2];
        a[2][2]=k-a[2][0]-a[2][1];
        /*
        for(i=0;i<3;i++)
            {
            for(j=0;j<3;j++)
                {
                printf("%d ",a[i][j]);
                }
            printf("\n");
            }
        system("pause");*/
        sum1[0]=a[0][0]+a[1][0]+a[2][0];
        sum1[1]=a[2][0]+a[2][2]+a[2][1];
        sum1[2]=a[1][0]+a[1][1]+a[1][2];
        sum1[3]=a[0][1]+a[1][1]+a[2][1];
        sum1[4]=a[0][2]+a[1][2]+a[2][2];
        sum1[5]=a[0][0]+a[1][0]+a[2][0];
        sum1[6]=a[0][0]+a[1][1]+a[2][2];
        sum1[7]=a[0][2]+a[1][1]+a[2][0];
        fl=0;
        for(i=1;i<8;i++)
            {
            if(sum1[i]!=sum1[0]){fl=1;break;}
            }
        if(fl==1 || a[0][0]<=0 || a[1][1]<=0 || a[2][2]<=0)continue ;
        for(i=0;i<3;i++)
            {
            for(j=0;j<3;j++)
                {
                printf("%d ",a[i][j]);
                }
            printf("\n");
            }
        return ;
        }
    }