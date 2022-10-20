#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;



struct mush
    {
    int num;
    double h;
    };


struct mush a[1050];

int f(struct mush x,struct mush y);

int main()
    {
    int n,t1,t2;
    int s1[1050];
    int s2[1050];
    int k;
    int i;
    scanf("%d%d%d%d",&n,&t1,&t2,&k);
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&s1[i],&s2[i]);
        }
    for(i=0;i<n;i++)
        {
        a[i].num=i+1;
        a[i].h=0.00;
        if(a[i].h<(s1[i]*t1)*(1.0-(double(k)/100.00))+s2[i]*t2)
            {
            a[i].h=(s1[i]*t1)*(1.0-(double(k)/100.00))+s2[i]*t2;
            }
        if(a[i].h<(s2[i]*t1)*(1.0-(double(k)/100.00))+s1[i]*t2)
            {
            a[i].h=(s2[i]*t1)*(1.0-(double(k)/100.00))+s1[i]*t2;
            }
        }
    sort(a,a+n,f);
    for(i=0;i<n;i++)
        {
           printf("%d %.2lf\n",a[i].num,a[i].h);
        }
    return 0;
    }


int f(struct mush x,struct mush y)
    {
    if(x.h>y.h)return true;
    if(x.h<y.h)return false;
    if(x.num<y.num)return true;
    else return false;
    }