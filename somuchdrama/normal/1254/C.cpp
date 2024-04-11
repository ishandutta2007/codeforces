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

const int N=1111;
int ask1(int i,int j,int k){
    cout<<"1 "<<i<<' '<<j <<' '<<k<<std::endl;
    int res;
    cin>>res;
    return res;
}
int ask2(int i,int j,int k){
    cout<<"2 "<<i<<' '<<j <<' '<<k<<std::endl;
    int res;
    cin>>res;
    return res;
}
int a[N];
int32_t main(){
    int n;
    cin>>n;
    int mn=2;
    for(int i=3;i<=n;++i){
        int s=ask2(1,mn,i);
        if(s==-1)mn=i;
    }
    dbg(mn);
    int mx=-1;
    for(int i=2;i<=n;++i){
        if(i==mn)continue;
        int s=ask1(1,mn,i);
        a[i]=s;
        if(mx==-1||a[i]>a[mx])mx=i;
    }
    dbg(mx);
    vector<pii> l,r;
    for(int i=2;i<=n;++i){
        if(i==mx)continue;
        int s=ask2(1,mx,i);
        if(s==+1)l.pb(a[i],i);
        else r.pb(a[i],i);
    }
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());
    sort(r.begin(), r.end());
    cout<<"0 1 ";
    for(pii p:r)cout<<p.s<<' ';
    cout<<mx<<' ';
    for(pii p:l)cout<<p.s<<' ';
    cout<<'\n';

    return 0;
}