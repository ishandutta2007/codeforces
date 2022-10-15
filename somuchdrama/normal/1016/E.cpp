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

const int N=2e5+5;
ll l[N],r[N];
ll a[N],p[N];

int main(){

    ll sy,x1,x2, n, q;
    cin >> sy>>x1>>x2>>n;

    for (int i = 1; i <= n; ++i){
        cin >> l[i] >> r[i];
        a[i] = r[i] - l[i];
        p[i] = p[i - 1] + a[i];
    }
    l[n+1] = 2e9;
        
    cin >> q;
    while(q--){
        ll x, y;
        cin>>x>>y;
        double ox1 = (x1 * y - sy * x) *1. / (y - sy);
        double ox2 = (x2 * y - sy * x) *1. / (y - sy);
        int wl = std::lower_bound(r, r + n + 1, ox1) - r;
        int wr = std::lower_bound(r, r + n + 1, ox2) - r;
        double ans = 0;
        if (wl == wr && l[wl] <= ox1 && ox1 <= r[wl] && l[wl] <= ox2 && ox2 <= r[wl]) {
            cout << x2-x1 << '\n';
            continue;
        }
        if (l[wl] <= ox1 && ox1 <= r[wl]) {
            ans += min(ox2, (double)r[wl]) - ox1;
            wl++;
        }
        if (l[wr] <= ox2 && ox2 <= r[wr]) {
            ans += ox2 - max(ox1, (double)l[wr]);
        }
        wr--;
        ans += p[wr] - p[wl - 1];
        ans *= (x2 - x1) / (ox2 - ox1);
        cout << ans << '\n';
    }


    return 0;
}