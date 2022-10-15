#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
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

const int N=1e6+6,M=998244353;
int dp[N][2][2];//i root l
int32_t main(){
    int n;
    cin>>n;
    dp[1][1][1]=1;
    dp[1][0][0]=1;
    dp[2][0][1]=1;
    dp[2][1][0]=1;
    for(int i=3;i<=n;++i){
        forn(si,2){
            if(i&1){
                int l=i/2,r=i/2;
                int sl=si,sr=si^((l+1)&1);
                int ri=si^(l&1);
                int rl=ri^1,rr=ri;
                if(si)dbg(l,r,ri,rl,rr,sl,sr);
                dp[i][ri][si]=(dp[l][rl][sl]*dp[r][rr][sr])%M;
            }else{
                {//mensiy root
                    //znachit menshe sleva
                    int l=i/2-1;
                    int r=i-1-l;
                    int sl=si,sr=si^((l+1)&1);

                    int ri=si^(l&1);

                    int rl=ri^1,rr=ri;
                    if(si)dbg(l,r,ri,rl,rr,sl,sr);
                    dp[i][ri][si]=(dp[l][rl][sl]*dp[r][rr][sr])%M;
                }
                {           
                    int r=i/2-1;
                    int l=i-1-r;
                    int sl=si,sr=si^((l+1)&1);

                    int ri=si^(l&1);

                    int rl=ri^1,rr=ri;
                    if(si)dbg(l,r,ri,rl,rr,sl,sr);
                    dp[i][ri][si]=(dp[l][rl][sl]*dp[r][rr][sr])%M;
                }
            }
            dp[i][0][si]%=M;
            dp[i][1][si]%=M;
            if(si)dbg(i,dp[i][0][1],dp[i][1][1]);
        }
    }
    cout<<(dp[n][0][1]+dp[n][1][1])%M<<'\n';

    return 0;
}