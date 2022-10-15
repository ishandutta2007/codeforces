#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
// #define int ll
// #define pii pll
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
const int N=150001,M=998244353,K=520;
void add(int&x,int y){
    x+=y;
    if(x>=M)x-=M;
}
int mul(int x,int y){
    return ((ll)x*y)%M;
}
int rev(int x,int m){
    if(x==1)return 1;
    return (1-(ll)rev(m%x,x)*m)/x+m;
}
vector<int> g[N];
int dep[N],tin[N],tout[N],size[N];
int timer=0;
bool anc(int v,int u){
    return tin[v]<tin[u]&&tout[u]<tout[v];
}
void dfs1(int v,int d=0,int p=0){
    dep[v]=d;
    tin[v]=timer++;
    size[v]=1;
    for(int to:g[v])if(to^p){
        dfs1(to,d+1,v);
        size[v]+=size[to];
    }
    tout[v]=timer++;
}
int w[N],d[N];
vector<pair<int,int>> la[N];
int al[N*K];
vector<int> st;
void dfs2(int v,int p=0){
    st.pb(v);
    for(auto& q:la[v])al[q.s]=st[q.f];
    for(int to:g[v])if(to^p)dfs2(to,v);
    st.pop_back();
}
int a[N],p[N],b[N];
int n,q;
int qu[N],pu[N];
void bfs3(){
    int l=0,r=0;
    qu[r++]=1;
    for(int i=1;i<=n;++i)pu[i]=-1;
    pu[1]=0;
    while(l<r){
        int v=qu[l++];
        int push=pu[v];
        add(push,p[v]);
        add(a[v],push);
        for(int to:g[v])if(pu[to]==-1){
            pu[to]=push+mul(b[v],(n-size[to]));
            if(pu[to]>=M)pu[to]-=M;
            qu[r++]=to;
        }
    }
}
int main(){
    cin>>n>>q;
    forn(i,n-1){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs1(1);
    vector<pii> act;
    int lq=0;
    for(int i=1;i<=q;++i){
        int t;
        cin>>t>>w[i];
        d[i]=-1;
        if(t==1){
            cin>>d[i];
            act.pb(w[i],d[i]);
        }else{
            for(const auto& [v,z]:act)
                if(anc(v,w[i]))
                    la[w[i]].pb(dep[v]+1,lq++);
        }
        if(i%K==0||i==q)act.clear();
    }
    dfs2(1);
    int invn=rev(n,M);
    lq=0;
    for(int i=1;i<=q;++i){
        if(d[i]!=-1){
            int v=w[i];
            act.pb(v,d[i]);
            add(b[v],d[i]);
            add(a[v],mul(d[i],n));
            p[v]-=mul(d[i],size[v]);
            if(p[v]<0)p[v]+=M;
            add(p[1],mul(d[i],size[v]));
        }else{
            int res=a[w[i]];
            for(const auto& [v,z]:act){
                if(anc(v,w[i])){
                    int e=al[lq++];
                    add(res,mul(z,(n-size[e])));
                }else if(v!=w[i]){
                    add(res,mul(z,size[v]));
                }
            }
            cout<<mul(res,invn)<<'\n';
        }
        if(i%K==0){
            bfs3();
            for(int j=1;j<=n;++j)p[j]=b[j]=0;
            act.clear();
        }
    }
    return 0;
}