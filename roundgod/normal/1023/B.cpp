/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-17 22:39:56
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
int main()
{
    scanf("%lld%lld",&n,&k);
    if(2*n-1<k) {puts("0"); return 0;}
    ll g=min(k-1,n);
    ll p=(k-g);
    printf("%lld\n",(g-p+1)/2);
    return 0;
}