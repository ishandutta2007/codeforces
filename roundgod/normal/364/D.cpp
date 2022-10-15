#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll a[MAXN];
mt19937 wcy(time(NULL));
vector<ll> d;
vector<int> cnt;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    ll ans=1;
    for(int k=0;k<10;k++)
    {
        int id=wcy()%n+1;
        d.clear();
        for(int j=1;1LL*j*j<=a[id];j++)
        {
            if(a[id]%j) continue;
            d.push_back(j);
            if(1LL*j*j!=a[id]) d.push_back(a[id]/j);
        }
        sort(d.begin(),d.end());
        cnt.clear();
        cnt.resize((int)d.size());
        for(int i=1;i<=n;i++)
        {
            ll g=__gcd(a[i],a[id]);
            int iid=lower_bound(d.begin(),d.end(),g)-d.begin();
            cnt[iid]++;
        }
        for(int j=0;j<(int)d.size();j++)
            for(int k=0;k<j;k++)
                if(d[j]%d[k]==0) cnt[k]+=cnt[j];
        for(int j=0;j<(int)d.size();j++) if(cnt[j]*2>=n) ans=max(ans,d[j]);
    }
    printf("%lld\n",ans);
    return 0;
}