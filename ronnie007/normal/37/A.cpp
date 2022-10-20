#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
    {
    int n;
    int a[1007];
    int br=0;
    int mx=0;
    int i;
    int br1=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    sort(a,a+n);
    br1=1;
    for(i=1;i<n;i++)
        {
        if(a[i]==a[i-1])br1++;
        else
            {
            br++;
            if(mx<br1)mx=br1;
            br1=1;
            }
        }
    br++;
    if(mx<br1)mx=br1;
    br1=0;
    printf("%d %d\n",mx,br);
    return 0;
    }