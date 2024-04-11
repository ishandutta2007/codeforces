#include<iostream>
#include<stdio.h>
using namespace std;

int n,m;
int a[600][600];
int ans[100007];
int best=0;
int br=0;

int ispr(int number);

int main()
    {
    int i,j;
    int number=1;
    for(i=1;i<=100000;i++)
        {
        number=i;
        while(ispr(number)==0)
            {
            number++;
            }
        ans[i]=number-i;
        }
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            scanf("%d",&a[i][j]);
            a[i][j]=ans[a[i][j]];
            }
        }
    br=0;
    best=10000000;
    for(i=0;i<n;i++)
        {
        br=0;
        for(j=0;j<m;j++)
            {
            br+=a[i][j];
            }
        if(br<best)best=br;
        }
    for(i=0;i<m;i++)
        {
        br=0;
        for(j=0;j<n;j++)
            {
            br+=a[j][i];
            }
        if(br<best)best=br;
        }
    printf("%d\n",best);
    return 0;
    }

int ispr(int number)
    {
    int i;
    if(number==1)return 0;
    for(i=2;i*i<=number;i++)
        {
        if(number%i==0)return 0;
        }
    return 1;
    }