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
const int N=5e5+5;
pair<vector<int>,int> g[N];
int32_t main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            g[i].f.clear();
            cin>>g[i].s;
        }
        forn(i,m){
            int a,b;
            cin>>a>>b;
            g[b].f.pb(a);
        }
        for(int i=1;i<=n;++i){
            sort(g[i].f.begin(), g[i].f.end());
        }
        sort(g+1,g+n+1);
        int ans=0;
        int sum=g[1].s;
        for(int i=2;i<=n;++i){
            if(g[i].f!=g[i-1].f){
                if(!g[i-1].f.empty())ans=std::gcd(ans,sum);
                sum=0;
            }
            sum+=g[i].s;
        }
        if(!g[n].f.empty())ans=std::gcd(ans,sum);
        cout<<ans<<'\n';
    }

    return 0;
}