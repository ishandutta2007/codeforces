#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;



int n;
long long k;

long long a[200007];


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
    scanf("%d%I64d",&n,&k);
    int i;
    for(i=1;i<=n;i++)
        {
        scanf("%I64d",&a[i]);
        }
    }


void solve()
    {
    long long t=0;
    long long ans=0;
    int br=0;
    int i;
    t=0;
    for(i=2;i<n;i++)
        {
        ans=t-((i-1-br)*(n-i)*a[i]);
        ///cout<<ans<<"\n";
        if(ans<k){printf("%d\n",i);br++;}
        else t=t+(a[i]*(i-br-1));
        ///printf("%d\n",t);
        }
    }