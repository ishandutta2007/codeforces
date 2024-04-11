#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;



void input();


int main()
    {
    input();
    return 0;
    }


void input()
    {
    int n;
    long long x,y;
    int i;
    long long k;
    long long num=0;
    scanf("%d%I64d",&n,&k);
    for(i=0;i<n;i++)
        {
        scanf("%I64d%I64d",&x,&y);
        num+=(y-x+1);
        }
    long long ans=(k-(num%k))%k;
    printf("%I64d\n",ans);
    }