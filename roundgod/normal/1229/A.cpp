#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
ll a[MAXN];
int b[MAXN];
map<ll,ll> cnt,sum;
vector<P> v;
vector<ll> taken;
int main()
{
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    ll s=0;
    for(int i=1;i<=n;i++)
    {
        cnt[a[i]]++;
        sum[a[i]]+=b[i];
    }
    ll allmask=0;
    int allcnt=0;
    for(auto x:cnt)
    {
        ll mask=x.F;
        if(cnt[mask]>=2)
        {
            s+=sum[mask];
            taken.push_back(mask);
            allcnt+=cnt[mask];
        }
        else v.push_back(P(mask,sum[mask]));
    }
    for(int i=0;i<(int)v.size();i++)
    {
        bool f=false;
        for(auto mask:taken) if((v[i].F&mask)==v[i].F) {f=true; break;}
        if(!f) continue;
        allcnt++;
        s+=v[i].S;
    }
    printf("%lld\n",s);
    return 0;
}