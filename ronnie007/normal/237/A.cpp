#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main()
    {
    int n;
    int a,b;
    int l,l1;
    l=-1;
    l1=-1;
    int br=1;
    int mx=0;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&a,&b);
        if(a==l && b==l1)br++;
        else
            {
            if(mx<br)mx=br;
            br=1;
            }
        l=a;
        l1=b;
        }
    if(mx<br)mx=br;
    printf("%d\n",mx);
    return 0;
    }