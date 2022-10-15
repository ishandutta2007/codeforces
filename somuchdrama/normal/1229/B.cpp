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
const int N=1e5+1,M=1e9+7,K=350;
int u[N];
int a[N];
vector<int> g[N];
vector<pii> way[N];
int ans=0;
void dfs(int v,int p=0,int curd=1){
    u[v]=1;
    int last=-1;
    for(pii z:way[p]){
        int o=std::gcd(z.f,a[v]);
        if(o==last){
            way[v].back().s+=z.s;
        }else{
            way[v].pb(o,z.s);
        }
        last=o;
    }
    if(a[v]==last)way[v].back().s++;
    else way[v].pb(a[v],1);
    for(pii z:way[v]){
        ans+=(z.f*z.s)%M;
        ans%=M;
    }
    for(int to:g[v]){
        if(!u[to]){
            dfs(to,v,curd+1);
        }
    }
}

int32_t main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    forn(i,n-1){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
    cout<<ans<<'\n';

    return 0;
}