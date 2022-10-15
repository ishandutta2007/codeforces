// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC optimize("O3,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define f first
#define s second
#define pb emplace_back
#define fon(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
                                                                                                                                                                                        // #define int ll

const int N=15e6+5;
int lp[N];
int pr[N];
int cpr = 0;
void calc_primes(int n) { 
    for (int i = 2; i <= n; ++i) {
        if (!lp[i])
            pr[cpr++] = lp[i] = i;
        for (int j = 0; j < cpr && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
            lp[i * pr[j]] = pr[j];
    }
} 
int c[N];
vector<pii> d;
int m;
void gen(int k=0,int p=1){
    if(k==m){
        c[p]++;
    }else{
        for(int i=0;i<=d[k].s;++i){
            gen(k+1,p);
            p*=d[k].f;
        }
    }
}
int32_t main() {
    calc_primes(N-1);
    int n;
    cin>>n;
    int g=0;
    // int ft=-1;
    // bool eq=1;
    fon(i,n){
        int x;
        cin>>x;
        g=std::gcd(x,g);
        // if(!i)ft=x;
        // else eq&=(ft==x);
        d.clear();
        while(x>1){
            int z=lp[x];
            d.pb(z,0);
            while(lp[x]==z){
                d.back().s++;
                x/=lp[x];
            }
        }
        m=d.size();
        gen();
    }

    dbg(g);

    int ans=n;
    for(int i=g+1;i<N;++i){
        if(i<10)
        dbg(i,c[i]);
        upn(ans,n-c[i]);
    }
    if(ans>=n)ans=-1;
    cout<<ans<<'\n';





    return 0;
}