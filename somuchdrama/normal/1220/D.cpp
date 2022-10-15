#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
const int N=2e5+1,B=64;
int a[N];
vector<int> v[B];
int32_t main(){

    int n;
    cin>>n;
    forn(i,n){
        cin>>a[i];
        for(int j=0;;j++){
            if(a[i]>>j&1){
                v[j].pb(a[i]);
                break;
            }
        }
    }
    int ans=0,wans=B-1;
    forn(i,B){
        if(v[i].size()>ans){
            ans=v[i].size();
            wans=i;
        }
    }
    cout<<n-ans<<'\n';
    forn(i,B){
        if(wans^i){
            for(int j:v[i])cout<<j<<' ';
        }
    }
    cout<<'\n';



    return 0;
}