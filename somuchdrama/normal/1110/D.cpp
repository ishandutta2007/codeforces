#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
using std::make_pair;
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x)((x)*(x))
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
// #define int ll
const int N=1e6+16,OO=1e9;
int dp[N][3][3];
int a[N];

int32_t main() {
    int n,m;
    cin>>n>>m;
    forn(i,n){
        int x;
        cin>>x;
        a[x]++;
    }
    forn(z,m+1)forn(i,3)forn(j,3)dp[z][i][j]=-OO;
    dp[0][0][0]=0;
    forn(i,m){
        forn(prev,3){
            forn(cur,3){
                int val=dp[i][prev][cur];
                forn(to,3){
                    if(a[i+1]<to+cur+prev)break;
                    int rem=a[i+1]-to-cur-prev;
                    upx(dp[i+1][cur][to],val+rem/3+prev);
                }
            }
        }
    }
    int ans=0;
    forn(z,m+1)forn(i,3)forn(j,3){
        if(dp[z][i][j]>=0)
        dbg(z,i,j,dp[z][i][j]);
        upx(ans,dp[z][i][j]);
    }
    cout<<ans<<'\n';


    
    return 0;
}