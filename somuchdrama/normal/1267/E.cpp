#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
#else
#define dbg(...)
#endif
struct init{init(){
#ifdef LOCAL
freopen("input.txt","r",stdin);
#endif // LOCAL
cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

int n, m;
int a[1001][1001];
#define endl "\n"

vector<int> get(int j){
    vector<pair<int,int>> pp;
    forn(i,m)
        pp.pb(a[i][j]-a[i][n-1],i);
    sort(pp.begin(),pp.end());
    int kek=0;
    vector<int>res;
    for(int i=m-1;i>=0;--i)
        if(kek+pp[i].f>=0)
            kek+=pp[i].f;
        else
            res.pb(pp[i].s);
    sort(res.begin(),res.end());
    return res;
}
int32_t main(){
    cin>>n>>m;
    forn(i,m)forn(j,n)cin>>a[i][j];
    vector<int> ans(m);
    std::iota(ans.begin(),ans.end(),0);
    forn(j,n-1){
        auto res=get(j);
        if(res.size()<ans.size())ans=res;
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i+1<<' ';
    cout<<endl;
    return 0;
}