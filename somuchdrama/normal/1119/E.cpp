#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _dbg(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_dbg(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define sz(a) ((int)a.size())
#define forn(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

const int N=3e5+5,OO=1e18;
int a[N];
pii dp[N][3];
pii operator +(pii p1,pii p2){
    p1.f+=p2.f;
    p1.s+=p2.s;
    return p1;
}
const pii bad={-OO,-OO};
int32_t main() {

    int n;
    cin>>n;
    forn(i,n+1)forn(j,3)dp[i][j]=bad;
    dp[0][0]={0,0};
    int ans=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        for(int j=0;j<3;++j){
            // dbg(i,j);
            forn(k,3){
                int s=a[i];
                pii was=dp[i-1][k];
                if(was!=bad){
                    // dbg(k,was.f,was.s);
                    pii nw={0,0};
                    s-=j;
                    if(s<0)continue;
                    int can=min(s/2,was.s);
                    nw.f+=can;
                    s-=can+can;
                    nw.f+=s/3;
                    nw.s+=j-can;
                    // dbg(can,nw.f,nw.s);
                    upx(dp[i][j],was+nw);
                }
            }
            // dbg(i,j,dp[i][j].f,dp[i][j].s);
            upx(ans,dp[i][j].f);
        }
    }
    cout<<ans<<'\n';
    return 0;
}