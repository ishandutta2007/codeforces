#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _dbg(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_dbg(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define sz(a) ((int)a.size())
#define forn(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

const int N=2e5+5,L=18;
int p[N],a[N],w[N];
int go[N][L];
int next[N];
struct segtree {
    int n,sh=1;
    vector<int>tree;
    segtree(int _n):n(_n){init();build();}
    template<class InputIterator>
    segtree(InputIterator begin,InputIterator end):n(int(end-begin)){
        init();
        std::copy(begin,end,tree.begin()+sh);
        build();
    }
    void init(){
        while(sh<n)sh*=2;
        tree.assign(sh*2,1e9);
    }
    void build(){for(int i=sh;--i;)tree[i]=min(tree[i+i],tree[i+i+1]);}
    int get(int l,int r){ 
        int res=1e9;
        for(l+=sh,r+=sh+1;l<r;l/=2,r/=2){
            if(l&1)upn(res,tree[l++]);
            if(r&1)upn(res,tree[--r]);
        }
        return res;
    }
};
int res[N];

int32_t main() {

    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i){
        cin>>p[i];
        w[p[i]]=i;
    }
    for(int i=1;i<=n+1;++i){
        next[i]=m+1;
    }
    for(int i=1;i<=m;++i){
        cin>>a[i];
        a[i]=w[a[i]];
    }
    forn(j,L)go[m+1][j]=m+1;

    for(int i=m;i>=1;--i){
        next[a[i]]=i;
        int kek=a[i]+1;
        if(kek>n)kek=1;
        go[i][0]=next[kek];
        for(int j=1;j<L;++j)
            go[i][j]=go[go[i][j-1]][j-1];
    }

    for(int i=1;i<=m;++i){
        int v=i,need=n-1;
        for(int j=L-1;j>=0;--j)
            if((1<<j)<need){
                need-=1<<j;
                v=go[v][j];
            }
        res[i]=go[v][0];
        dbg(i,v,res[i]);
    }

    segtree st(res,res+m+1);
    while(q--){
        int l,r;
        cin>>l>>r;
        if(st.get(l,r)<=r)cout<<'1';
        else cout<<'0';
    }
    cout<<'\n';


    return 0;
}