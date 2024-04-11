#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
ll b[MAXN];
ll ans=INF;
void solve(int id)
{
    memset(b,0,sizeof(b));
    ll tmp=0;
    for(int i=id-1;i>=1;i--)
    {
        ll need=(-b[i+1]+a[i])/a[i];
        tmp+=need;
        b[i]=-need*a[i];
    }
    for(int i=id+1;i<=n;i++)
    {
        ll need=(b[i-1]+a[i])/a[i];
        tmp+=need;
        b[i]=need*a[i];
    }
    ans=min(ans,tmp);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) solve(i);
    printf("%lld\n",ans);
    return 0;
}