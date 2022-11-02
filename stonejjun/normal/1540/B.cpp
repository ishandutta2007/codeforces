#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;

#define ff first
#define ss secondac
#define eb emplace_back
#define ep emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) lower_bound(all(v), x) - v.begin()
//cout<<fixed;
//cout.precision(12);

struct poi{
    ll val,xx,yy;
};

vector<ll> x;
ll n,m;
ll mod=1e9+7;
string s;
string t;
ll arr[1010101];
vector<ll> v[1010101];
ll dep[1010101];
ll vis[1010101];
ll par[1000][20];
ll revt;
ll revtm[1010];
ll rt;

void dfs(ll x,ll d){
    vis[x]=1;
    dep[x]=d;
    for(auto k:v[x]){
        if(vis[k]) continue;
        par[k][0]=x;
        dfs(k,d+1);
    }
}


void f(){
    ll i,j;
    for(j=1;j<11;j++)
        for(i=1;i<=n;i++)
            par[i][j]=par[par[i][j-1]][j-1];
}

ll lca(ll x,ll y){
    if(dep[x]>dep[y]) swap(x,y);
    for(int i=10;i>=0;i--){
        if(dep[y]-dep[x]>=(1<<i)) y=par[y][i];
    }

    if(x==y) return x;
    for(int i=10;i>=0;i--){
        if(par[x][i]!=par[y][i]){
            x=par[x][i];
            y=par[y][i];
        }
    }
    return par[x][0];
}

ll lsp(ll a,ll b){
    ll ret=1;
    while(b){
        if(b%2) ret=(ret*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ret;
}

ll gin(ll x){
    return lsp(x,mod-2)%mod;
}

ll ans=0;

ll dp[510][510];

ll sol(ll a,ll b){
    ll lab=lca(a,b);
    if(a<=b) return 0;
    //cout<<"qwe"<<a<<' '<<b<<' '<<dep[a]-dep[lab]<<' '<<dep[b]-dep[lab]<<'\n';
    return dp[dep[a]-dep[lab]][dep[b]-dep[lab]]%mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k;
    cin>>n;
    ll a,b,c,d;

    for(i=1;i<=n;i++){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    revt=gin(2);
    revtm[0]=gin(n);
    for(i=1;i<=n;i++){
        revtm[i]=(revtm[i-1]*revt)%mod;
    }

    for(i=1;i<=n;i++){
        dp[0][i]=gin(n);
        dp[i][0]=0;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            dp[i][j]=(dp[i-1][j]*revt+dp[i][j-1]*revt)%mod;
        }

    for(rt=1;rt<=n;rt++){
        for(i=1;i<=n;i++){
            dep[i]=vis[i]=0;
            par[i][0]=0;
        }
        dfs(rt,1);
        par[rt][0]=rt;
        f();

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++){
                ll qwe=sol(i,j);
                ans=(ans+qwe)%mod;
                //cout<<rt<<' '<<i<<' '<<j<<' '<<qwe<<'\n';
            }

    }

    cout<<ans;


    
}