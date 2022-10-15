/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-18 22:45:13
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
ll n,q,x,y;
int main()
{
    scanf("%lld%lld",&n,&q);
    for(ll i=0;i<q;i++)
    {
        scanf("%lld%lld",&x,&y);
        ll ans=0;
        ans+=(x-1)/2*n;
        x=x&1;if(x==0) x+=2;
        ans+=(y-1)/2+1;
        if((x+y)&1) ans+=(n*n+1)/2;
        if(x==2)
        {
            if((x+y)&1) ans+=n/2;
            else ans+=(n+1)/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}