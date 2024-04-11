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

int32_t main() {
    
    int n,m;
    string s, t;
    cin >> n>>m>>s >> t;
    int w=-1;
    for (int i =0;i<n;++i)
        if (s[i]=='*')
            w=i;
    if (w==-1){
        if (s==t)cout<<"YES\n";
        else cout<<"NO\n";
    }else{
        if (s.substr(0,w)==t.substr(0,w)){
            s=s.substr(w+1);
            t=t.substr(w);
            reverse(s.begin(), s.end());
            reverse(t.begin(), t.end());
            n=s.size();
            m=t.size();
            if (m>=n&&t.substr(0,n)==s)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";
    }

    

    return 0;
}