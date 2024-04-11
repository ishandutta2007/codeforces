#include <bits/stdc++.h>
using namespace std; 
  
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
  
double EPS = 1e-9;      
int INF = 1000000005; 
long long INFF = 1000000000000000005LL; 
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 }; 
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 }; 
  
#ifdef TESTING 
#define DEBUG fprintf(stderr, "====TESTING====\n") 
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl 
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#else 
#define DEBUG 
#define VALUE(x) 
#define debug(...) 
#endif 

#define tezi                ios_base::sync_with_stdio(false);\
                            cin.tie(0);\
                            cout.tie(0);        
#define endl                "\n"  
#define FOR(a, b, c)        for (int(a) = (b); (a) < (c); ++(a)) 
#define FORN(a, b, c)       for (int(a) = (b); (a) <= (c); ++(a)) 
#define FORD(a, b, c)       for (int(a) = (b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c)      for (int(a) = (b); (a) * (a) <= (c); ++(a)) 
#define FORC(a, b, c)       for (char(a) = (b); (a) <= (c); ++(a))
#define rep(i, n)           FOR(i, 0, n) 
#define repn(i, n)          FORN(i, 1, n) 
#define MAX(a, b)           a = max(a, b) 
#define MIN(a, b)           a = min(a, b) 
#define SQR(x)              ((ll)(x) * (x)) 
#define RESET(a, b)         memset(a, b, sizeof(a)) 
#define fi                  first 
#define se                  second 
#define mp                  make_pair 
#define pb                  push_back 
#define ALL(v)              v.begin(), v.end() 
#define ALLA(arr, sz)       arr, arr + sz 
#define SIZE(v)             (int)v.size() 
#define SORT(v)             sort(ALL(v)) 
#define REVERSE(v)          reverse(ALL(v)) 
#define SORTA(arr, sz)      sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz)   reverse(ALLA(arr, sz)) 
#define PERMUTE             next_permutation 
#define tc(t)               while (t--)

ll power(ll x,ll y){
    if(y==0) return 1;
    return x*power(x,y-1); 
}
vector<bool> vis;
vvi g1,g2,g3;
int cmp1[200005]={0};
int cmp2[200005]={0};
int cmp3[200005]={0};
    
struct LCA{
    int p[200005];
    int b_p[200005][21];
    int level[200005];
    void dfs(vvi &g,int n,int e,int l,int k,int ok){
        p[n]=e;
        vis[n]=1;
        level[n]=l;
        if(ok==1) cmp2[n]=k;
        if(ok==0) cmp1[n]=k;
        if(ok==2) cmp3[n]=k;
        for(auto i:g[n]){
            if(i!=e){
                dfs(g,i,n,l+1,k,ok);
            }
        }
        return;
    }
    void lift(int n){
        for(int i=0;i<=20;i++){
            for(int j=1;j<=n;j++){
                if(i==0)b_p[j][i]=p[j];
                else b_p[j][i]=b_p[b_p[j][i-1]][i-1];
            }
        }
        return;
    }
    int lca(int u, int v){
        if(level[v]<level[u])u=v+u-(v=u);
        int diff=level[u]-level[v];
        for (int i=20;i >= 0; i--) {
                if (level[v]-level[u] >=(1 << i)) {
                    v = b_p[v][i];
                }
        }
        if(v==u){
            return u;
        }
        int k=20;
        while(k>=0){
                if(b_p[u][k]!=b_p[v][k]){
                    u=b_p[u][k];
                    v=b_p[v][k];
                }
                k--;
        } 
        return p[u];
    }
}l1,l2,l3;

int main(){
    tezi
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    
    int n;
    cin >> n;
    g1.resize(n),g2.resize(n),g3.resize(n);
    FOR(i,0,n){
        cmp1[i]=cmp2[i]=-1,cmp3[i]=-1;
        int p,t;
        cin >> p >> t;
        if(p==-1)continue;
        p--;
        if(t==0){
            g1[p].pb(i);
        }else{
            g2[p].pb(i);
        }
        g3[p].pb(i);
    }
    vis.resize(n,0);
    FOR(i,0,n)vis[i]=0;
    FOR(i,0,n){
        if(!vis[i]) l1.dfs(g1,i,i,0,i,0);
    }
    l1.lift(n);
    FOR(i,0,n)vis[i]=0;
    FOR(i,0,n){
        if(!vis[i]) l2.dfs(g2,i,i,0,i,1);
    }
    l2.lift(n);
    FOR(i,0,n)vis[i]=0;
    FOR(i,0,n){
        if(!vis[i]){
            l3.dfs(g3,i,i,0,i,2);
        }
    }
    l3.lift(n);
    int q;
    cin >> q;
    while(q--){
        int t,u,v;
        cin >> t >> u >> v;
        u--,v--;
        if(u==v){
            cout << "NO\n";
            continue;
        }
        if(t==1){
            if(cmp1[u]!=cmp1[v] || cmp1[u]==-1 || cmp1[v]==-1){
                cout << "NO\n";
                continue;
            }
            if(l1.lca(u,v)==u){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            if(cmp3[u]!=cmp3[v] || cmp3[u]==-1 || cmp3[v]==-1){
                cout << "NO\n";
                continue;
            }
            int w = l3.lca(u,v);
            if(cmp1[u]!=cmp1[w] || cmp1[u]==-1 || cmp1[w]==-1 || w==v){
                cout << "NO\n";
                continue;
            }
            if(cmp2[v]!=cmp2[w] || cmp2[w]==-1 || cmp2[w]==-1){
                cout << "NO\n";
                continue;
            }
            if(l1.lca(u,w)==w && l2.lca(v,w)==w){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}


/*
######                  ####### #     #   ###   #     #    #    ####### ####### ######
#     #  ######  #    # #     # ##   ##    #    ##    #   # #      #    #     # #     #
#     #  #       ##   # #     # # # # #    #    # #   #  #   #     #    #     # #     #
#     #  #####   # #  # #     # #  #  #    #    #  #  # #     #    #    #     # ######
#     #  #       #  # # #     # #     #    #    #   # # #######    #    #     # #   #
#     #  #       #   ## #     # #     #    #    #    ## #     #    #    #     # #    #
######   ######  #    # ####### #     #   ###   #     # #     #    #    ####### #     #
*/