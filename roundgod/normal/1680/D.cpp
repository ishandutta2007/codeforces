#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
ll a[MAXN],cnt[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) 
    {
        if(a[i]==0) cnt[i]=1;
        a[i]+=a[i-1];
        cnt[i]+=cnt[i-1];
    }
    ll ans=1;
    if(a[n]-1LL*k*cnt[n]>0||a[n]+1LL*k*cnt[n]<0) {puts("-1"); return 0;}
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            ll cura=a[j]-a[i-1];
            ll na=a[n]-cura;
            ll curcnt=cnt[j]-cnt[i-1];
            ll ncnt=cnt[n]-curcnt;
            ll lb=max(cura-curcnt*k,-(na+ncnt*k));
            ll rb=min(cura+curcnt*k,-(na-ncnt*k));
            ans=max(ans,max(-lb,lb)+1); ans=max(ans,max(-rb,rb)+1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}