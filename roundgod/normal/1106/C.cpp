#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i<=n/2;i++) ans+=1LL*(a[i]+a[n+1-i])*(a[i]+a[n+1-i]);
    printf("%lld\n",ans);
    return 0;
}