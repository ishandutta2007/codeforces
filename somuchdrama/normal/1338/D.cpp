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
const int N=1e5+5;
vector<int> g[N];
int dp[N][2];
int ans=0;
void dfs(int v,int p=0){
    dp[v][0]=1;
    dp[v][1]=0;
    int ch=sz(g[v])-(!!p);
    int mx1=0,sx1=0,mx=0,sx=0;
    for(int to:g[v]){
        if(to^p){
            dfs(to,v);
            upx(dp[v][0],dp[to][1]+1);
            upx(dp[v][1],max(dp[to][0],dp[to][1])+ch-1);
            upx(sx1,dp[to][1]);
            if(mx1<sx1)swap(mx1,sx1);
            upx(sx,max(dp[to][0],dp[to][1]));
            if(mx<sx)swap(mx,sx);
        }
    }
    upx(ans,mx1+sx1+1);
    upx(ans,mx+sx+sz(g[v])-2);
}
int32_t main(){
    int n;
    cin>>n;
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int i=1;i<=n;++i){
        if(g[i].size()>1){
            dfs(i);
            break;
        }
    }
    cout<<ans<<'\n';
    return 0;
}