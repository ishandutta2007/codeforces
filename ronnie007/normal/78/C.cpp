#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;




int main()
    {
    long long n,m,k;
    long long i;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    if(k==1 && m!=1)
        {
        if(n%2)printf("Timur\n");
        else printf("Marsel\n");
        return 0;
        }
    if(n%2==0)
        {
        printf("Marsel\n");
        return 0;
        }
    int f=0;
    for(i=2;i*i<=m;i++)
        {
        if(m%i==0 && (m/i>=k || i>=k))
            {
            f=1;
            break;
            }
        }
    if(f==1)printf("Timur\n");
    else printf("Marsel\n");
    return 0;
    }