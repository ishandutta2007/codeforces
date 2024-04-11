#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define f first
#define s second
#define pb emplace_back
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;

const int N=2e5;
int a[N],b[N];

int32_t main() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i]>>b[i];

    set<int> pot;
    int e=a[0];
    for (int i =2;i*i<=a[0];++i){
        if(e%i==0){
            pot.insert(i);
            while(e%i==0)e/=i;
        }
    }
    if(e^1)pot.insert(e);
    e=b[0];
    for (int i =2;i*i<=b[0];++i){
        if(e%i==0){
            pot.insert(i);
            while(e%i==0)e/=i;
        }
    }
    if(e^1)pot.insert(e);
    for(int x:pot){
        bool f=1;
        for(int i=1;i<n;++i){
            if(a[i]%x==0||b[i]%x==0) {
                ;
            }else f=0;
        }
        if(f){
            cout<<x<<'\n';
            return 0;
        }
    }
    cout<<"-1\n";

    return 0;
}