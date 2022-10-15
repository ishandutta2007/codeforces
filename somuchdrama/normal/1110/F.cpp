#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
using std::make_pair;
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x)((x)*(x))
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
#define int ll
const int N=5e5+1;
const ll OO=1e16;
vector<pii> g[N];
struct qu{
    int l,r,i;
    qu(){}
    qu(int _l,int _r,int _i):l(_l),r(_r),i(_i){}
};
vector<qu> qs[N];
int ans[N];
int tree[N*4],mod[N*4],sh=1,d[N],mn[N],mx[N];
int n,q;
void apply(int v,int x){
    tree[v]+=x;
    mod[v]+=x;
}
void push(int v,int tl,int tr){
    if(tl!=tr){
        apply(v+v,mod[v]);
        apply(v+v+1,mod[v]);
        mod[v]=0;
    }
}
void recalc(int v){
    tree[v]=min(tree[v+v],tree[v+v+1]);
}
void build(){for(int i=sh-1;i>0;--i)recalc(i);}
int get(int v,int tl,int tr,int l,int r){
    if(l>tr||r<tl)return OO;
    if(l<=tl&&tr<=r)return tree[v];
    push(v,tl,tr);
    int tm=(tl+tr)/2;
    int res=OO;
    if(tm>=l)upn(res,get(v+v,tl,tm,l,r));
    if(tm+1<=r)upn(res,get(v+v+1,tm+1,tr,l,r));
    return res;
}
void add(int v,int tl,int tr,int l,int r,int val){
    if(l<=tl&&tr<=r){
        apply(v,val);
        return;
    }
    push(v,tl,tr);
    int tm=(tl+tr)/2;
    if(tm>=l)add(v+v,tl,tm,l,r,val);
    if(tm+1<=r)add(v+v+1,tm+1,tr,l,r,val);
    recalc(v);
}
void add(int l,int r,int val){
    add(1,0,sh-1,l,r,val);
}
int get(int l,int r){
    return get(1,0,sh-1,l,r);
}
void dfs1(int v,int dist=0){
    mn[v]=mx[v]=v;
    for(pii e:g[v]){
        dfs1(e.f,dist+e.s);
        upn(mn[v],mn[e.f]);
        upx(mx[v],mx[e.f]);
    }
    if(g[v].empty())d[v]=dist;
    else d[v]=OO;
}
void dfs2(int v,int xex=0){
    for(qu&u:qs[v]){
        ans[u.i]=get(u.l,u.r)+xex;
    }
    for(pii e:g[v]){
        int to=e.f;
        add(mn[to],mx[to],-e.s-e.s);
        dfs2(to,xex+e.s);
        add(mn[to],mx[to],+e.s+e.s);
    }
}
int32_t main() {
    cin>>n>>q;
    for(int i=2;i<=n;++i){
        int p,w;
        cin>>p>>w;
        g[p].pb(i,w);
    }
    forn(i,q){
        int v,l,r;
        cin>>v>>l>>r;
        qs[v].pb(l,r,i);
    }
    while(sh<n+1)sh*=2;
    forn(i,sh*2)tree[i]=OO;
    forn(i,sh*2)mod[i]=0;
    dfs1(1);
    for(int i=1;i<=n;++i)
        tree[i+sh]=d[i];
    build();
    dfs2(1);
    forn(i,q)cout<<ans[i]<<'\n';
    return 0;
}