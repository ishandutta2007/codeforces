#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::pair;using std::set;using std::string;using std::vector;
using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;
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

const int N=3e5+5;
ll d1[N],dn[N];
bool u[N];
vector<pll> g[N];
void dfsdist(int v, ll * ds, ll d = 0) {
    u[v] = 1;
    ds[v] = d;
    for (pll to : g[v]) {
        if (!u[to.ff]) {
            dfsdist(to.ff, ds, d + to.ss);
        }
    }
}

vector<int> way;
int n,q;
bool dfs1(int v) {
    u[v]=1;
    way.pb(v);
    if (v == n) return 1;
    for (pll to : g[v]){
        if (!u[to.ff]){
            if (dfs1(to.ff)) return 1;
        }
    }
    way.pop_back();
    return 0;
}
bool f = 0;
int dfs2(int v) {
    u[v] = 1;
    int c = 1;
    for (pll to : g[v]) {
        if (!u[to.ff]) {
            c += dfs2(to.ff);
        }
    }
    if (c >= 3) f = 1;
    return c;
}
int tor[N],tol[N];
int main(){

    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;   
        g[x].pb(y, z);
        g[y].pb(x, z);
    }
    dfsdist(1, d1);
    memset(u,0,sizeof u);
    dfsdist(n, dn);
    memset(u,0,sizeof u);

    dfs1(1);
    memset(u,0,sizeof u);
    for (int i : way)
        u[i] = 1;

    for (int i : way) {
        if (dfs2(i) >= 3) {
            f = 1;
        }
    }

    memset(u,0,sizeof u);
    for (int i : way)
        u[i] = 1;
    for (int i : way) {
        for (pll j : g[i]) {
            if (!u[j.ff]) {
                tor[i] = j.ff;
                tol[j.ff] = i;
            }
        }
    }

    ll mx = 0;
    for (int i = 0; i < way.size(); ++i) {
        if (i + 2 < way.size()) {
            mx = max(mx, d1[way[i]] + dn[way[i + 2]]);
        }
        if (i + 1 < way.size() && tor[way[i+1]]) {
            mx = max(mx, d1[way[i]] + dn[tor[way[i + 1]]]);
        }
        if (i + 1 < way.size() && tor[way[i]]&& tor[way[i+1]]) {
            mx = max(mx, d1[tor[way[i]]] + dn[tor[way[i + 1]]]);
        }
        if (i + 1 < way.size() && tor[way[i]]) {
            mx = max(mx, d1[tor[way[i]]] + dn[way[i + 1]]);
        }
    }

    while (q--) {
        ll x;
        cin >> x;
        if (f) {
            cout << d1[n] << '\n';
        } else {
            cout << min(d1[n], mx+x)<<'\n';
        }
    }


    return 0;
}