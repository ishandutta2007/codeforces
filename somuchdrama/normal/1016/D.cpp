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

const int N=111;
int a[N], b[N];
int ans[N][N];

int main(){

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int j = 0; j < m; ++j)
        cin >> b[j];


    for (int bit = 30; bit >= 0; --bit) {
        vector<int> as, bs;
        for (int i = 0; i < n; ++i)
            if (a[i]>>bit&1)
                as.pb(i);
        for (int i = 0; i < m; ++i)
            if (b[i]>>bit&1)
                bs.pb(i);
        int sa = as.size(), sb = bs.size();

        if ((sa+sb)&1) {
            cout << "NO\n";
            return 0;
        }

        while (as.size() > bs.size()) {
            int x;
            x = as.back();
            ans[x][0] ^= (1<<bit);
            as.pop_back();
            x = as.back();
            ans[x][0] ^= (1<<bit);
            as.pop_back();
        }
        while (bs.size() > as.size()) {
            int x;
            x = bs.back();
            ans[0][x] ^= (1<<bit);
            bs.pop_back();
            x = bs.back();
            ans[0][x] ^= (1<<bit);
            bs.pop_back();
        }
        for (int i = 0; i < as.size(); ++i) {
            ans[as[i]][bs[i]] ^= (1<<bit);
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}