#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN];
int cnt[MAXN];
multiset<ll> s;
vector<P> v;
int main()
{
    for(int i=1;i<=6;i++) scanf("%d",&a[i]);
    sort(a+1,a+7);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=6;j++)
            v.push_back(P(b[i]-a[j],i));
    sort(v.begin(),v.end());
    if(n==1)
    {
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;i++) s.insert(b[i]-a[6]);
    ll ans=INF;
    for(auto p:v)
    {
        int pos=p.S;
        cnt[pos]++;
        s.erase(s.find(b[pos]-a[7-cnt[pos]]));
        ans=min(ans,1LL*(*(--s.end())-p.F));
        if(cnt[pos]==6) break;
        s.insert(b[pos]-a[6-cnt[pos]]);
    }
    printf("%lld\n",ans);
    return 0;
}