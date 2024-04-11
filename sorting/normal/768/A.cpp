#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main ()
{
    int n,a[100000],i,j;

    scanf("%d",&n);

    for(i=0;i<n;i++)scanf("%d",&a[i]);

    sort(a,a+n);

    if(n<=2)
    {
        printf("0\n");
        return 0;
    }

    for(i=1;i<n-1;i++)
    {
        if(a[i]>a[0])break;
    }

    for(j=n-2;j>=0;j--)
    {
        if(a[j]<a[n-1])break;
    }

    if(i>j)
    {
        printf("0\n");
        return 0;
    }

    j=j-i+1;

    printf("%d\n",j);

    return 0;
}