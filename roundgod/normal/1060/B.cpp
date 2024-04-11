/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-04 15:07:11
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
ll n;
int main()
{
    scanf("%lld",&n);
    ll ans=0;
    while(n>0)
    {
        if(n<10) {ans+=n; break;}
        else if(n%10==9)
        {
            ans+=9;
            n=n/10;
        }
        else
        {
            ans+=(10+n%10);
            n=n/10-1;
        }
    }
    printf("%lld\n",ans);
}