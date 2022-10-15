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
int c[N];
void dfs1(int v,int cc){
    c[v]=cc;
    for(int to:g[v]){
        if(!c[to]){
            dfs1(to,3-cc);
        }
    }
}
int u[N];
int mx=0;
void dfs2(int v){
    u[v]=1;
    int h=0;
    for(int to:g[v]){
        if(!u[to]){
            if(g[to].size()==1){
                if(!h){
                    mx++;
                    dfs2(to);
                    h=1;
                }
            }else{
                mx++;
                dfs2(to);
            }
        }
    }
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
    dfs1(1,1);
    int el=0,er=0;
    for(int i=1;i<=n;++i){
        if(g[i].size()==1){
            if(c[i]==1)el=1;
            else er=1;
        }
    }
    int mn=1;
    if(el&&er)mn=3;
    for(int i=1;i<=n;++i)
        if(g[i].size()>1){
            dfs2(i);
            break;
        }
    cout<<mn<<' '<<mx<<'\n';

    return 0;
}