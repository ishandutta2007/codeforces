#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int a[100007];
int b[100007];

int main()
    {
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        b[i]=a[i];
        }
    sort(b,b+n);
    int br=0;
    for(i=0;i<n;i++)
        {
        if(a[i]!=b[i])br++;
        }
    if(br!=2 && br!=0)
        {
        printf("NO\n");
        }
    else printf("YES\n");
    return 0;
    }