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
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};
const int N=3e5+5;
int a[N],b[N],p[N],sum,n,las;
int kek(int i){
    if(!i||i==las)return 1;
    int pos=lower_bound(p,p+n-1,i)-p;
    int f=a[pos];
    int r=i-(pos?p[pos-1]+1:1ll);
    if(r&1){
        if(r==b[pos]-1)return a[pos+1];
        return f;
    }else{
        return 1+f+(r/2);
    }
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>n>>l>>r;
        sum=0;las=n*(n-1);
        a[0]=1;
        b[0]=n+n-2;
        sum=p[0]=b[0];
        for(int i=1;i<n-1;++i){
            a[i]=i+1;
            b[i]=2*(n-i)-2;
            p[i]=p[i-1]+b[i];
            sum+=b[i];
        }
        for(int i=l-1;i<=r-1;++i)cout<<kek(i)<<' ';
        cout<<'\n';
    }

    return 0;
}