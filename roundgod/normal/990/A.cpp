/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-10 17:59:20
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
ll n,m,a,b;
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
    ll r=n%m;
    printf("%lld\n",min(r*b,(m-r)*a));
    return 0;
}