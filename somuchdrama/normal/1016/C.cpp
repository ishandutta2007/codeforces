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
ll a[N],b[N],ai[N],bi[N],ad[N],bd[N],as[N],bs[N];

int main(){

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; ++i) {
        as[i] = as[i - 1] + a[i];
        bs[i] = bs[i - 1] + b[i];
        ai[i] = ai[i - 1] + (i - 1) * a[i];
        bi[i] = bi[i - 1] + (i - 1) * b[i];
    }
    for (int i = n, j = 0; i >= 1; --i, ++j) {
        ad[i] = ad[i + 1] + j * a[i];
        bd[i] = bd[i + 1] + j * b[i];        
    }

    ll ans = ai[n] - as[n] + bd[1] + bs[n] * (n - 1);

    ll c = 0, s = 0;
    for (int i = 0; i <= n; ++i) {
        ll pot;
        dbg(i, s);
        if (i & 1) {
            pot = s + bi[n] - bi[i] + (bs[n] - bs[i]) * (c - i) + ad[i + 1] + (as[n] - as[i]) * (n - i + c);
            s += b[i+1] * (c++);
            s += a[i+1] * (c++);
        } else {
            pot = s + ai[n] - ai[i] + (as[n] - as[i]) * (c - i) + bd[i + 1] + (bs[n] - bs[i]) * (n - i + c);
            // dbg(ai[n] - ai[i]);
            // dbg(as[n] - as[i]);
            // dbg(ai[n] - ai[i] + (as[n] - as[i]) * (c - i));
            s += a[i+1] * (c++);
            s += b[i+1] * (c++);
        }
        dbg(i, pot);
        if (ans < pot)
            ans = pot;
    }
    cout<<ans<<'\n';

    return 0;
}