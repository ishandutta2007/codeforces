/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-23 21:05:09
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
ll n,m,k;
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    ll S=2*n*m;
    if(S%k) {puts("NO"); return 0;}
    S/=k;
    ll x,y;
    if(__gcd(2*n,k)!=1)
    {
        ll g1=__gcd(2*n,k);x=2*n/g1;k/=g1;
        ll g2=__gcd(m,k);y=m/g2;k/=g2;
        assert(k==1);
    }
    else
    {
        ll g1=__gcd(2*m,k);y=2*m/g1;k/=g1;
        ll g2=__gcd(n,k);x=n/g2;k/=g2;
        assert(k==1);
    }
    if(x>n||y>m) {puts("NO"); return 0;}
    puts("YES");
    printf("0 0\n");
    printf("%lld 0\n",x);
    printf("0 %lld\n",y);
    return 0;
}