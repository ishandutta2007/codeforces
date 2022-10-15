/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-31 22:49:02
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
ll n,k,s;
int main()
{
    scanf("%lld%lld%lld",&n,&k,&s);
    if(k*(n-1)<s||k>s) {puts("NO"); return 0;}
    puts("YES");
    ll now=1;
    for(ll i=0;i<k;i++)
    {
        if(s-(n-1)<k-1-i)
        {
            ll dis=s-(k-1-i);
            if(now==1) 
            {
                printf("%lld ",dis+1);
                now=dis+1;
            }
            else
            {
                printf("%lld ",n-dis);
                now=n-dis;
            }
            for(ll j=i+1;j<k;j++)
            {
                if(now+1<=n) now++;
                else now--;
                printf("%lld ",now);
            }
            return 0;
        }
        else
        {
            s-=n-1;
            if(now==1) now=n; else now=1;
            printf("%lld ",now);
        }
    }
    return 0;
}