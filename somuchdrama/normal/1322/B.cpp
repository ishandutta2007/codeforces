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
const int N=5e5+5,B=24;
int a[N],b[N];
int32_t main(){
    int n;
    cin>>n;
    forn(i,n)cin>>a[i];
    int ans=0;
    for(int bit=B;bit>=0;--bit){
        int p=1<<bit;
        forn(i,n)b[i]=a[i]%(p+p);
        sort(b,b+n);
        int c=0;
        forn(i,n){
            int x=b[i];
            auto p1=std::lower_bound(b+i+1,b+n,1*p-x);
            auto p2=std::prev(std::lower_bound(b+i+1,b+n,2*p-x));
            auto p3=std::lower_bound(b+i+1,b+n,3*p-x);
            auto p4=std::prev(std::lower_bound(b+i+1,b+n,4*p-x));
            c+=p2-p1+1;
            c+=p4-p3+1;
        }
        if(c&1)ans+=p;
    }
    cout<<ans<<'\n';
    return 0;
}