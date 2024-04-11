#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;


int main()
    {
    int n;
    int i;
    int a[3000];
    int sum=0;
    int sum1=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        sum+=a[i];
        }
    int x,y;
    int min=1000000;
    scanf("%d%d",&x,&y);
    if(x>y)swap(x,y);
    for(i=x;i<y;i++)
        {
        sum1+=a[i];
        }
    if(sum1>sum-sum1)sum1=sum-sum1;
    printf("%d\n",sum1);
    return 0;
    }