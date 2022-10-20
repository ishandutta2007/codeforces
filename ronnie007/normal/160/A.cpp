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
    sum=0;
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        sum+=a[i];
        }
    sort(a,a+n);
    int h=0;
    for(i=n-1;i>=0;i--)
        {
        m++;
        h+=a[i];
        if(h>sum/2)
            {
            printf("%d\n",m);
            break;
            }
        }
    return 0;
    }