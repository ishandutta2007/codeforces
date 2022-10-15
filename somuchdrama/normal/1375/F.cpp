#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};
const int N=3e5+5;

int32_t main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<"First"<<std::endl;
    int big=1e10;
    cout<<big<<std::endl;
    int x;cin>>x;
    if(x==1)a+=big;
    if(x==2)b+=big;
    if(x==3)c+=big;
    int mx=max({a,b,c});
    int mn=min({a,b,c});
    int mi=a^b^c^mx^mn;
    // dbg(a,b,c,mn,mi,mx);
    int val=mx+mx-mn-mi;
    cout<<val<<std::endl;
    cin>>x;
    if(x==1)a+=val;
    if(x==2)b+=val;
    if(x==3)c+=val;
    mx=max({a,b,c});
    mn=min({a,b,c});
    mi=a^b^c^mx^mn;
    // dbg(a,b,c,mn,mi,mx);
    assert(mx-mi==mi-mn);
    int dif=mx-mi;
    cout<<dif<<std::endl;
    cin>>x;
    return 0;
}