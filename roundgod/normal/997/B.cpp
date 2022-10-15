/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-01 22:13:07
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
ll n,k,a[MAXN];
set<int> s;
int main()
{
    scanf("%lld",&n);
    if(n<=28)
    {
        for(ll a=0;a<=n;a++)
            for(ll b=0;a+b<=n;b++)
                for(ll c=0;a+b+c<=n;c++)
                    {
                        ll d=n-a-b-c;
                        s.insert(a+5*b+10*c+50*d);
                    }
        printf("%lld\n",(ll)s.size());
        return 0;
    }
    else printf("%lld\n",49LL*(n-28)+1125);
    return 0;
}