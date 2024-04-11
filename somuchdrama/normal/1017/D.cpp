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
const int B = 12, K = 101;
int c[B];
int cnt[1<<B];
int a[1<<B][(1<<B)+1];
int s[1<<B][(1<<B)+1];
int cc[B*K];
int len[1<<B];

int main(){

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    while (m--) {
        string st;
        cin >> st;
        int x=0;
        for (int i = 0; i < n; ++i)
            if (st[i] == '1')
                x|=(1<<i);
        cnt[x]++;
    }

    for (int m1 = 0; m1 < (1<<n); ++m1) {
        for (int m2 = 0; m2 < (1<<n);++m2) {
            int x = m1^m2;
            int ss = 0;
            for (int b = 0; b < n; ++b)
                if ((x>>b&1)==0)
                    ss += c[b];
            cc[ss]+=cnt[m2];
        }
        int ptr = 1;
        for (int i = 0; i < B*K; ++i) {
            if (cc[i]) {
                a[m1][ptr] = i;
                s[m1][ptr] = s[m1][ptr - 1] + cc[i];
                cc[i]=0;
                ptr++;
            }
        }
        len[m1] = ptr;
    }

    while (q--) {
        int k;
        string st;
        cin >> st >> k;
        int x=0;
        for (int i = 0; i < n; ++i)
            if (st[i] == '1')
                x|=(1<<i);
        int ptr = std::upper_bound(a[x], a[x] + len[x], k) - a[x] - 1;
        cout << s[x][ptr] << '\n';
    }


    return 0;
}