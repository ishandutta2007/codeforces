/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-07 22:37:47
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
ll q,n,m,k;
int main()
{
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        if(n==0&&m==0&&k==1) {puts("-1"); continue;}
        if(max(n,m)>k) {puts("-1"); continue;}
        if((n+k)%2==1&&(m+k)%2==1) printf("%lld\n",k-2);
        else if((n+k)%2==0&&(m+k)%2==0) printf("%lld\n",k);
        else printf("%lld\n",k-1);
    }
    return 0;
}