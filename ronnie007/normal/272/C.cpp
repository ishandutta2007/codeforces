#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
long long a[100007];
long long h,w;
long long level;

void input();




int main()
    {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input();
    return 0;
    }


void input()
    {
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        {
        scanf("%I64d",&a[i]);
        }
    level=a[0];
    scanf("%d",&m);
    for(i=0;i<m;i++)
        {
        scanf("%I64d%I64d",&w,&h);
        printf("%I64d\n",max(level,a[w-1]));
        level=max(level,a[w-1])+h;
        }
    }