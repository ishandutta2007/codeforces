#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
    {
    int a[100007];
    int n;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    sort(a,a+n);
    for(i=1;i<n;i++)
        {
        if(a[i]%a[0]!=0)
            {
            printf("-1");
            return 0;
            }
        }
    printf("%d\n",a[0]);
    return 0;
    }