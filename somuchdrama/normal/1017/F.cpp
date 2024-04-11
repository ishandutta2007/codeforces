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

const int SN = 100000; 
const int S = 10000;
bool nprime[SN], bl[S];
uint primes[SN], cnt;
uint n,a,b,c,d;
uint f(uint x)  {
    return a * x * x * x + b * x * x + c * x + d;    
}
uint contribution(uint x) {
    uint ans = 0;
    for (ll di = x; n/di; di *= x) {
        ans += n / di;
    }
    return ans;
}
int main() {
 
    cin >> n>>a>>b>>c>>d;
    int nsqrt = sqrt(n);
    for (int i=2; i<=nsqrt; ++i)
        if (!nprime[i]) {
            primes[cnt++] = i;
            if (i * 1ll * i <= nsqrt)
                for (int j=i*i; j<=nsqrt; j+=i)
                    nprime[j] = true;
        }
    uint ans = 0;
    for (int k=0, maxk=n/S; k<=maxk; ++k) {
        memset (bl, 0, sizeof bl);
        int start = k * S;
        for (int i=0; i<cnt; ++i) {
            int start_idx = (start + primes[i] - 1) / primes[i];
            int j = max(start_idx,2) * primes[i] - start;
            for (; j<S; j+=primes[i])
                bl[j] = true;
        }
        if (k == 0)
            bl[0] = bl[1] = true;
        for (int i=0; i<S && start+i<=n; ++i)
            if (!bl[i]){
                ans += contribution(start+i) * f(start+i);
            }
    }
    cout << ans << '\n';
    return 0;
}