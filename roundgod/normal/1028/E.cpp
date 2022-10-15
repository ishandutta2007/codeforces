/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-28 01:25:01
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
ll n,k,a[MAXN];
ll ans[MAXN];
ll mx=0;
bool f=false;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        if(i!=1&&a[i]!=mx) f=true;
        mx=max(mx,a[i]);
    }
    if(mx==0)
    {
        puts("YES");
        for(ll i=1;i<n;i++) printf("1 ");
        puts("1");
        return 0;
    }
    if(!f) {puts("NO"); return 0;}
    puts("YES");
    for(ll i=1;i<=n;i++)
    {
        if(a[i%n+1]>a[i])
        {
            ans[i%n+1]=a[i%n+1];
            for(ll j=i;j!=i%n+1;j=(j-1)+n*(j==1))
            {
                ans[j]=ans[j%n+1]+a[j];
                if(ans[j]<INF) ans[j]=ans[j]+ans[j%n+1]*(INF/ans[j%n+1]+1);
            }
            for(ll j=1;j<=n;j++) printf("%lld ",ans[j]);
            return 0;
        }
    }
    return 0;
}