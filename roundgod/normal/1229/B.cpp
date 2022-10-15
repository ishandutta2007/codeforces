#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,ans;
ll a[MAXN];
vector<int> G[MAXN];
map<ll,int> mp[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dfs(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        for(auto pr:mp[v])
        {
            ll g=__gcd(pr.F,a[to]);
            add(ans,1LL*g*pr.S%MOD);
            mp[to][g]+=pr.S;
        }
        mp[to][a[to]]++;
        add(ans,1LL*a[to]%MOD);
        dfs(to,v);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    ans=(1LL*a[1]%MOD);
    mp[1][a[1]]++;
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}