#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll arr[10101010];
ll dp[10101010];
ll brr[10101010];
string s;

int main()
{
	ll i,j,k,l,m,n,r,anslo=0,anshi=0;
	scanf("%lld %lld %lld",&n,&l,&r);
	for(i=0;i<l;i++)
    {
        anslo+=(ll)(1<<i);
    }
    anslo+=(n-l);
    for(i=0;i<r;i++)
    {
        anshi+=(ll)(1<<i);
    }
    r--;
    anshi+=(1<<r)*(n-1-r);
    printf("%lld %lld",anslo,anshi);
}