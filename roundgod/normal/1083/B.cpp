/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-11 01:07:53
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
ll n,k;
string s,t;
int main()
{
    scanf("%lld%lld",&n,&k);
    cin>>s;cin>>t;
    ll ans=0,cnt=0;
    for(ll i=0;i<n;i++)
    {
        cnt=cnt*2+(int)t[i]-(int)s[i];
        if(cnt>k+1) cnt=k+1;
        ans+=min(cnt+1,k);
    }
    printf("%lld\n",ans);
    return 0;
}