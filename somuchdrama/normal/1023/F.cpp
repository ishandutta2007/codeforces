#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
const int N=5e5+1;
vector<pii> g[N];
int a[N],b[N],c[N];
int p[N];
int get(int x){
    return x==p[x]?x:(p[x]=get(p[x]));
}
int dep[N],up[N],go[N];
void dfs(int v,int f=0,int val=0){
    dep[v]=dep[f]+1;
    p[v]=v;
    go[v]=f;
    up[v]=val;
    for(pii e:g[v])
        if(e.f^f)
            dfs(e.f,v,e.s);
}
int ans=0;
int boom(int v,int val){
    if(!up[v]){
        up[v]=val;
        ans+=val;
    }
    return p[v]=get(go[v]);
}
void join(int u,int v,int val){
    while(u^v){
        dbg(u,dep[u],v,dep[v]);
        if(dep[u]>dep[v]) u=boom(u,val);
        else v=boom(v,val);
    }
}

int32_t main(){
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=1;i<=n;++i)p[i]=i;
    forn(i,k){
        int x,y;
        cin>>x>>y;
        g[x].pb(y,0);
        g[y].pb(x,0);
        y=get(y);
        x=get(x);
        p[y]=x;
    }
    forn(i,m){
        cin>>a[i]>>b[i]>>c[i];
        if(get(a[i])^get(b[i])){
            p[get(a[i])]=p[get(b[i])];
            g[a[i]].pb(b[i],c[i]);
            g[b[i]].pb(a[i],c[i]);
        }
    }
    dfs(1);
    dbg("tut");
    forn(i,m){
        dbg(a[i],b[i]);
        if(get(a[i])^get(b[i])){
            join(a[i],b[i],c[i]);
        }
    }
    for(int i=2;i<=n;++i){
        if(!up[i]){
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<ans<<'\n';
    return 0;
}