#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.be,x.ee
#define le (x*2)
#define ri (x*2+1)
#define mid ((l+r)/2)
#define ld long double
#define e '\n'
#define sp ' '
#define pb push_back
#define pf push_front
#define up upper_bound
#define lo lower_bound
#define in insert
#define mk make_pair
#define er erase
#define R return
#define se second
#define co continue
#define fi first
#define fr front()
#define ba back()
#define si size()
#define em empty()
#define be begin()
#define ee end()
#define ep 0.0000001
#define pi acos(-1)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int32_t mod=1e9+7, m1=1e9+123, m2=1e9+321;
static const int base=uniform_int_distribution<int>(300,(int)1e9+122)(rng);
static inline int add(int a,int b,int Mod) {
    R ((ll)a+b)%Mod;
}
static inline int sub(int a,int b,int Mod) {
    R (((ll)a-b)%Mod+Mod)%Mod;
}
static inline int mul(int a,int b,int Mod){
    R 1ll*a*b%Mod;
}

static const int N=(int)1e5+10;
int n,m,ans[N],st[N],ft[N],ver[N],t=1,lvl[N],sz[N],id[N],mxlvl[N];
set<int> se[N];
vi adj[N];
vector<pii> query[N];
void dfs(int v,int h){
    mxlvl[v]=lvl[v]=h;
    ver[t]=v;
    st[v]=t++;
    sz[v]=1;
    for(auto u:adj[v]){
        dfs(u,h+1);
        sz[v]+=sz[u];
        mxlvl[v]=max(mxlvl[v],mxlvl[u]);
    }
    ft[v]=t;
}
void ddfs(int v,bool keep){
    int mx=-1, child=-1;
    for(auto u:adj[v]){
        if(sz[u]>mx){
            mx=sz[u];
            child=u;
        }
    }
    for(auto u:adj[v]){
        if(u!=child) ddfs(u,0);
    }
    if(child!=-1) ddfs(child,1);
    se[lvl[v]].in(id[v]);
    for(auto u:adj[v]){
        if(u!=child){
            for(int p=st[u];p<ft[u];p++){
                se[lvl[ver[p]]].in(id[ver[p]]);
            }
        }
    }
    for(auto x:query[v]){
        int h=x.fi, i=x.se;
        ans[i]=(int)se[min(N-1,lvl[v]+h)].si;
    }
    if(keep==0){
        for(int p=st[v];p<ft[v];p++){
            se[lvl[ver[p]]].erase(id[ver[p]]);
        }
    }
}

int main(){
    scanf("%d",&n);
    map<string,int> vis;
    char buff[22];
    string t;
    int k=1;
    for(int i=1;i<=n;i++){
        int pa; scanf("%s%d",&buff,&pa);
        adj[pa].pb(i);
        t=buff;
        if(!vis[t]){
            id[i]=k;
            vis[t]=k++;
        }
        else id[i]=vis[t];
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int v,h; scanf("%d%d",&v,&h);
        query[v].pb({h,i});
    }
    dfs(0,0);
    ddfs(0,0);
    for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    R 0;
}