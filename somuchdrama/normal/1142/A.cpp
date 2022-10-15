#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _dbg(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_dbg(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define sz(a) ((int)a.size())
#define forn(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}


int32_t main() {

    int n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<int> pa,pb;
    if(!a)pa.pb(0);
    else{
        pa.pb(a);
        pa.pb(k-a);
    }
    if(!b)pb.pb(0);
    else{
        pb.pb(b);
        pb.pb(k-b);
    }

    int mn=1e12,mx=0;
    for(int s1:pa){
        for(int s2:pb){
            int to=s2;
            if(s2<=s1)to+=k;
            forn(i,n){
                int l=to-s1;
                int cnt=(n*k)/std::gcd(l,n*k);
                upn(mn,cnt);
                upx(mx,cnt);
                to+=k;
            }
        }
    }
    cout<<mn<<' ' <<mx<<'\n';
    
    return 0;
}