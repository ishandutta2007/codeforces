#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
    {
    int n;
    int a[1057];
    int i,j;
    int mn=100000;
    int mx=0;
    int ind1;
    int ind2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    for(i=0;i<n;i++)
        {
        if(mx<a[i])
            {
            mx=a[i];
            ind1=i;
            }
        if(mn>a[i])
            {
            mn=a[i];
            ind2=i;
            }
        }
    if(mx==mn){printf("Exemplary pages.\n");return 0;}
    if((mx-mn)%2==1){printf("Unrecoverable configuration.\n");return 0;}
    int x=(mx+mn)/2;
    int br=0;
    for(i=0;i<n;i++)
        {
        if(a[i]!=x)br++;
        }
    if(br!=2){printf("Unrecoverable configuration.\n");return 0;}
    printf("%d ml. from cup #%d to cup #%d.\n",(mx-mn)/2,ind2+1,ind1+1);
    return 0;
    }