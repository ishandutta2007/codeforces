#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
const int N = 1e5+1;

int main(){

    int n;
    cin >> n;
    int sq = sqrt(n);
    int bl = n / sq;

    for (int i = 1; i <= bl; ++i) {
        for (int j = i * sq; j > (i - 1) * sq; --j)
            cout << j << ' ';
    }

    while (n % sq != 0) {
        cout << n-- << ' ';
    }
    cout << '\n';




    return 0;
}