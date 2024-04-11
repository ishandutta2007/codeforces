#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

int main()
    {
    int n;
    int a[100007];
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    sort(a,a+n);
    int diff;
    for(i=1;i<n;i++)
        {
        diff=a[i]-a[i-1];
        if(diff<=a[i-1]-1 && a[i]!=a[i-1])
            {
            printf("YES\n");
            return 0;
            }
        }
   printf("NO\n");
    return 0;
    }