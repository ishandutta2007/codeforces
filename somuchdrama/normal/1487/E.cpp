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

const int N=202020,K=4,OO=1e9;
int n[K];
int a[K][N];
vector<int> g[K][N];
int t[N*4];
int dp[K][N];
int s;
void build(int l){
    s=1;
    while(s<n[l])s*=2;
    forn(i,s+s)t[i]=OO;
    forn(i,n[l])t[i+s]=dp[l][i];
    for(int i=s;--i;)t[i]=min(t[i+i],t[i+i+1]);
}
void upd(int i,int val){for(t[i+=s]=val;i/=2;)t[i]=min(t[i+i],t[i+i+1]);}
int get(int l,int r){
    int res=OO;
    for(l+=s,r+=s+1;l<r;l/=2,r/=2){
        if(l&1)upn(res,t[l++]);
        if(r&1)upn(res,t[--r]);
    }
    return res;
}
int32_t main(){
    forn(i,K)cin>>n[i];
    forn(i,K)forn(j,n[i])cin>>a[i][j];
    for(int l=1;l<K;++l){
        int e;
        cin>>e;
        while(e--){
            int x,y;
            cin>>x>>y;
            --x;--y;
            g[l][y].pb(x);
        }
    }
    forn(i,n[0])dp[0][i]=a[0][i];
    for(int l=1;l<K;++l){
        build(l-1);
        // forn(i,s+s)dbg(i,t[i]);
        forn(i,n[l]){
            for(int j:g[l][i]){
                upd(j,OO);
            }
            dp[l][i]=t[1]+a[l][i];
            // dbg(l,i,dp[l][i]);
            for(int j:g[l][i]){
                upd(j,dp[l-1][j]);
            }
        }
    }
    int ans=OO;
    forn(i,n[3])upn(ans,dp[3][i]);
    if(ans>=OO)ans=-1;
    cout<<ans<<'\n';

    return 0;
}