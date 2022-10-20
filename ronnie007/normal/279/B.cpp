#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


long long n,k;
long long a[100007];


void input();
void solve();




int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%I64d%I64d",&n,&k);
    int i;
    for(i=0;i<n;i++)
        {
        scanf("%I64d",&a[i]);
        }
    }



void solve()
    {
    long long br=0;
    long long mx=0;
    int i;
    long long sum=0;
    for(i=0;i<n;i++)
        {
        if(sum>k)
            {
            sum-=a[i-br];
            br--;
            }
        mx=max(mx,br);
        sum+=a[i];
        br++;
        }
    if(sum>k)
        {
        sum-=a[i-br];
        br--;
        }
    mx=max(mx,br);
    printf("%I64d\n",mx);
    }