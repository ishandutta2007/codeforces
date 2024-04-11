#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
// #define int ll
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::pair;using std::set;using std::string;using std::vector;
using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;
#define ff first
#define ss second
#define pb emplace_back
template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}
template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
cerr<<"Time elaped: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#endif
}}init;

const int N=3018;
int p[N],c[N];
vector<int> cs[N];
bool u[N];
vector<int> al;
int32_t main(){

    int n, m;
    cin >> n >> m;
    int c1=0;
    for (int i = 1; i <= n; ++i){
        cin >> p[i] >> c[i];
        c1 += p[i] == 1;
        cs[p[i]].pb(i);
        if (p[i]^1)
            al.pb(i);
    }
    for(int i=1;i<=m;++i)
        sort(cs[i].begin(), cs[i].end(), [&](int x, int y) {return c[x]<c[y];});
    sort(al.begin(), al.end(), [&](int x, int y) {return c[x]<c[y];});

    ll ans = 1e18;
    for (int w=max(1,c1); w<=n;++w) {
        memset(u, 0, sizeof u);
        ll pot = 0;
        int g = c1;
        dbg(w, g);
        for (int i = 2; i<=m;++i) {
            int pa = max(0, (int)cs[i].size() - w + 1);
            dbg(i, pa);
            for (int j = 0; j < pa; ++j){
                pot += c[cs[i][j]];
                g++;
                u[cs[i][j]] = 1;
            }
        }
        for (int i = 0; i < al.size() && g<w; ++i) {
            if (!u[al[i]]) {
                pot += c[al[i]];
                g++;
            }
        }
        dbg(pot);
        if(g==w&&ans>pot)
            ans = pot;
    }
    cout<<ans<<'\n';




    return 0;
}