#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
    {
    int n;
    int a[150];
    int sum=0;
    int i;
    int m=0;
    scanf("%d",&n);
    for(i=0;i<12;i++)
        {
        scanf("%d",&a[i]);
        }
    sort(a,a+12);
    int h=0;
    if(n==0)
        {
        printf("0\n");
        return 0;
        }
    for(i=11;i>=0;i--)
        {
        m++;
        h+=a[i];
        if(h>=n)
            {
            printf("%d\n",m);
            break;
            }
        }
    if(h<n)printf("-1\n");
    return 0;
    }