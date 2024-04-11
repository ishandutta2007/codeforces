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
ll n;
ll s;
ll dep[MAXN],fa[MAXN];
vector<ll> node[MAXN];
bool C(ll x)
{
    ll cnt=1,ss=1,now=1,ans=1;
    while(true)
    {
        now=now*x;
        cnt++;
        if(ss+now>n) break; else {ss+=now; ans+=cnt*now;}
    }
    ans+=cnt*(n-ss);
    return ans<=s;
}
int main()
{
    scanf("%lld%lld",&n,&s);
    if(1LL*n*(n+1)/2<s||2*n-1>s) {puts("No"); return 0;}
    puts("Yes");
    ll l=0,r=n-1;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(C(mid)) r=mid; else l=mid;
    }
    ll curans=1LL*n*(n+1)/2;
    for(ll i=1;i<=n;i++) dep[i]=1;
    ll now=n,cur=2;
    while(curans>s)
    {
        while(!dep[now]) now--;
        while(dep[cur]==1LL*dep[cur-1]*r) cur++;
        assert(now>cur);
        while(now-cur>curans-s) cur++;
        dep[now]--;dep[cur]++;
        curans-=now-cur;
    }
    ll tot=1;
    node[1].push_back(1);
    for(ll i=2;i<=n;i++)
    {
        ll mem=tot+1;
        for(ll j=1;j<=dep[i];j++) node[i].push_back(++tot);
        ll sz=(int)node[i-1].size();
        for(auto v:node[i]) fa[v]=node[i-1][0]+(v-mem)%sz;
    }
    assert(tot==n);
    for(ll i=2;i<=n;i++) printf("%lld ",fa[i]);
    return 0;
}