#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
// #define int ll
// #define pii pll
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
const int N=14;
int g[N][N];
vector<int> w[1<<N][N][N];
vector<int> c[1<<N];
int dp[1<<N];
pii f[1<<N];

int32_t main() {
    int n,m;
    cin>>n>>m;
    forn(i,m){
        int a,b;
        cin>>a>>b;
        --a,--b;
        g[a][b]=1;
        g[b][a]=1;
    }
    forn(i,n)w[1<<i][i][i]={i};
    forn(mask,1<<n){
        if(__builtin_popcount(mask)<=1)continue;
        forn(s,n){
            if(mask>>s&1){
                forn(i,n)if(mask>>i&1)forn(prev,n)if(!w[mask^(1<<i)][s][prev].empty()&&g[prev][i]){
                    w[mask][s][i]=w[mask^(1<<i)][s][prev];
                    w[mask][s][i].pb(i);
                    break;
                }
                if(__builtin_popcount(mask)>2&&c[mask].empty())
                    forn(i,n)if(!w[mask][s][i].empty()&&g[i][s]){
                        c[mask]=w[mask][s][i];
                        break;
                    }
            }
        }
    }
    forn(mask,1<<n){
        if(!c[mask].empty()){
            dp[mask]=c[mask].size(),f[mask]={mask,0};
        }
        else dp[mask]=1e9;
        for(int submask=mask;submask!=0;submask=(submask-1)&mask){
            if(submask==mask)continue;
            if(c[submask].empty())continue;
            forn(i,n)if(submask>>i&1){
                int was=mask^submask^(1<<i);
                int pot=c[submask].size()+dp[was];
                if(dp[mask]>pot){
                    dp[mask]=pot;
                    f[mask]={submask,1<<i};
                }
            }
        }
        for(int submask=mask;submask!=0;submask=(submask-1)&mask){
            if(submask==mask)continue;
            forn(i,n)if(submask>>i&1)forn(j,n)if(submask>>j&1)if(i^j){
                if(w[submask][i][j].size()<3)continue;
                int was=mask^submask^(1<<i)^(1<<j);
                int pot=w[submask][i][j].size()+dp[was]-1;
                if(dp[mask]>pot){
                    dp[mask]=pot;
                    f[mask]={submask,(1<<i)^(1<<j)};
                }
            }
        }
    }
    cout<<dp[(1<<n)-1]<<'\n';
    int mask=(1<<n)-1;
    while(mask){
        int i=-1,j=-1;
        forn(bit,n)if(f[mask].s>>bit&1){
            if(i==-1)i=bit;
            else j=bit;
        }
        if(j<0){
            auto v=c[f[mask].f];
            forn(k,v.size())
                cout<<v[k]+1<<' '<<v[(k+1)%v.size()]+1<<'\n';
        }else{
            auto v=w[f[mask].f][i][j];
            forn(k,v.size()-1)
                cout<<v[k]+1<<' '<<v[k+1]+1<<'\n';
        }
        mask^=f[mask].f^f[mask].s;
    }
    return 0;
}