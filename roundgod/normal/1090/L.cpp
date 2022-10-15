/*************************************************************************
    > File Name: L.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-09 16:52:33
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,n,a,b,k;
int main()
{
    scanf("%lld%lld%lld%lld%lld",&t,&n,&a,&b,&k);
    if(k>n)
    {
        puts("0");
        return 0;
    }
    ll fst,scd; scd=n/2; fst=n-scd;
    ll ans=(fst*a+scd*b)/k;
    ll needf=k-scd;
    if(needf>0) ans=min(ans,fst*a/needf);
    ll needs=k-fst;
    if(needs>0) ans=min(ans,scd*b/needs);
    printf("%lld\n",min(ans,t));
    return 0;
}