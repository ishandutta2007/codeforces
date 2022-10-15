/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-04 15:14:50
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
ll n,k,l[MAXN],r[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++) scanf("%lld%lld",&l[i],&r[i]);
    sort(l,l+n);sort(r,r+n);
    for(ll i=0;i<n;i++) k+=max(l[i],r[i]);
    printf("%lld\n",k+n);
    return 0;
}