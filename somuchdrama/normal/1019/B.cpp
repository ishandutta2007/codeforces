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

const int N=1e5+1;

int a[N];
int ask(int i) {
    if (a[i]!=-1) return a[i];
    cout << "? " << i << std::endl;
    cin >> a[i];
    return a[i];
}
int32_t main(){

    int n;
    cin>>n;
    if ((n/2)&1) {
        cout<<"! -1\n";
        return 0;
    }

    memset(a, -1, sizeof a);

    int l = 1, r = n/2+1;
    if (ask(l) == ask(r)) {
        cout << "! " << l << '\n';
        return 0;
    }

    while (1) {
        int m = (l+r)/2;
        bool bl = ask(l)>ask(l+n/2);
        bool bm = ask(m)>ask(m+n/2);
        if (ask(m)==ask(m+n/2)){
            cout<<"! " << m << '\n';
            return 0;
        }
        if (bl == bm)
            l = m;
        else
            r = m;
    }

    return 0;
}