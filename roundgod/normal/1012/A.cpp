/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-02 17:22:58
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*n;i++) scanf("%d",&a[i]);
    sort(a,a+2*n);
    ll ans=1LL*(a[n-1]-a[0])*(a[2*n-1]-a[n]);
    ll res=a[2*n-1]-a[0];
    for(int i=0;i<n;i++) ans=min(ans,res*(a[i+n-1]-a[i]));
    printf("%lld\n",ans);
    return 0;
}