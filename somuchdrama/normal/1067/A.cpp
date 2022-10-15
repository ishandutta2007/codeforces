#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define f first
#define s second
#define pb emplace_back
#define fon(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
const int N=1e5+5,K=202;
int a[N];
int dp[N][K][2];
int sum[N][K][2];
int mus[N][K][2];
const ll M=998244353;

int32_t main() {

    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    dp[0][0][0]=1;
    sum[0][0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=200;++j){
            sum[i-1][j][0]=(sum[i-1][j-1][0]+dp[i-1][j][0])%M;
            sum[i-1][j][1]=(sum[i-1][j-1][1]+dp[i-1][j][1])%M;
        }
        for(int j=200;j>=1;--j){
            mus[i-1][j][0]=(mus[i-1][j+1][0]+dp[i-1][j][0])%M;
            mus[i-1][j][1]=(mus[i-1][j+1][1]+dp[i-1][j][1])%M;
        }
        if(a[i]==-1){
            for(int j=1;j<=200;++j){
                dp[i][j][0]=(sum[i-1][j-1][0]+sum[i-1][j-1][1])%M;
                dp[i][j][1]=(dp[i-1][j][0]+mus[i-1][j][1])%M;
            }
        }else{
            int j=a[i];
            dp[i][j][0]=(sum[i-1][j-1][0]+sum[i-1][j-1][1])%M;
            dp[i][j][1]=(dp[i-1][j][0]+mus[i-1][j][1])%M;
        }
    }

    int ans=0;
    for(int j=1;j<=200;++j)
        ans=(ans+dp[n][j][1])%M;
    
    cout<<ans<<'\n';


    return 0;
}