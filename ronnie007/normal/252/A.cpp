#include<iostream>
#include<stdio.h>
using namespace std;




int main()
    {
    int n;
    int a[150];
    scanf("%d",&n);
    int i,j;
    int mx=0;
    int br=0;
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    for(i=0;i<n;i++)
        {
        br=0;
        for(j=i;j<n;j++)
            {
            br=br^a[j];
            if(mx<br)mx=br;
            }
        if(mx<br)mx=br;
        }
    printf("%d\n",mx);
    return 0;
    }