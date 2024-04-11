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

const int N=5e5+5,M=998244353;
int t[N];

int l[N],r[N],x[N],a[N],f[N],p[N],dp[N];

int32_t main(){
    int n,k,m;
    cin>>n>>k>>m;
    forn(i,m)cin>>l[i]>>r[i]>>x[i];
    int ans=1;
    forn(bit,k){
        dbg(bit);
        for(int i=1;i<=n;++i){
            t[i]=0;
            f[i]=0;
            a[i]=0;
            dp[i]=0;
        }
        dp[0]=1;
        forn(i,m){
            if(x[i]>>bit&1){
                a[l[i]]++;
                a[r[i]+1]--;
            }else{
                upx(f[r[i]],l[i]);
            }
        }
        p[0]=dp[0]=1;
        for(int i=1;i<=n;++i){
            a[i]+=a[i-1];
            upx(f[i],f[i-1]);
            if(!a[i]){
                dp[i]=p[i-1];
                if(f[i-1])dp[i]-=p[f[i-1]-1];
                if(dp[i]<0)dp[i]+=M;
            }
            p[i]=p[i-1]+dp[i];
            if(p[i]>=M)p[i]-=M;
        }
        int res=p[n];
        if(f[n])res-=p[f[n]-1];
        if(res<0)res+=M;
        (ans*=res)%=M;
    }
    cout<<ans<<'\n';
    return 0;
}