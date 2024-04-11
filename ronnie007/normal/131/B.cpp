#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
    {
    int n,m;
    int i,j;
    int c;
    int a[100007];
    scanf("%d",&n);
    long long br=0;
    for(i=0;i<100000;i++)
        {
        a[i]=0;
        }
    for(i=0;i<n;i++)
        {
        scanf("%d",&c);
        br+=a[100-c];
        a[100+c]++;
        }
    cout<<br<<"\n";
    return 0;
    }