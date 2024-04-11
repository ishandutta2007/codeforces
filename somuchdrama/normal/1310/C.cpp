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
const int N=1010,OO=1e18+123456789;
void add(int&x,int y){
    if((x+=y)>OO)x=OO;
}
int n,m,k;
int dp[N][N],lc[N][N];
pair<string,int> su[N];
string s;
bool ch(int l,int r){
    dbg(l,r,s.substr(l,r-l+1));
    int le=r-l+1;
    memset(dp,0,sizeof dp);
    dp[n][0]=1;
    int res=0;
    for(int i=n-1;i>=0;--i){
        dp[i][0]=1;
        if(lc[l][i]<le){
            int ke=lc[l][i]+1;
            char ci=s[i+ke-1],cl=s[l+ke-1];
            if(ci<cl){
                for(int j=m;j>=1;--j){
                    dp[i][j]=dp[i+1][j];
                    dbg(i,j,dp[i][j],dp[i][j]-dp[i+1][j]);
                }
                continue;
            }else{
                for(int j=m;j>=1;--j){
                    dp[i][j]=dp[i+1][j];
                    add(dp[i][j],dp[i+ke][j-1]);
                    if(j==m&&i==0)res=dp[i+ke][j-1];
                    dbg(i,j,dp[i][j],dp[i][j]-dp[i+1][j]);
                }
            }
        }else{
            int ke=le;
            for(int j=m;j>=1;--j){
                dp[i][j]=dp[i+1][j];
                add(dp[i][j],dp[i+ke][j-1]);
                if(j==m&&i==0)res=dp[i+ke][j-1];
                dbg(i,j,dp[i][j],dp[i][j]-dp[i+1][j]);
            }
        }
    }
    dbg(s.substr(l,r-l+1),res);
    dbg("==========");
    return res>=k;
}
int32_t main(){
    cin>>n>>m>>k>>s;
    s+="$";
    forn(i,n)su[i]={s.substr(i),i};
    sort(su,su+n);
    forn(i,n-1){
        int x=su[i].s,y=su[i+1].s;
        forn(j,n){
            if(su[i].f[j]!=su[i+1].f[j]){
                lc[x][y]=lc[y][x]=j;
                break;
            }
        }
    }
    forn(i,n)lc[i][i]=n-i;
    forn(i,n){
        int x=su[i].s;
        for(int j=i+1;j<n;++j){
            int y=su[j].s;
            int z=su[j-1].s;
            lc[y][x]=lc[x][y]=min(lc[x][z],lc[z][y]);
        }
    }
    vector<pii> po;
    int la=0;
    forn(i,n){
        int x=su[i].s;
        for(int j=la;j+x<n;++j)po.pb(x,x+j);
        if(i!=n-1)la=lc[x][su[i+1].s];
    }
    // forn(i,po.size())ch(po[i].f,po[i].s);
    int l=0,r=po.size();
    while(r-l>1){
        int mi=(l+r)/2;
        if(ch(po[mi].f,po[mi].s))l=mi;
        else r=mi;
    }
    cout<<s.substr(po[l].f,po[l].s-po[l].f+1)<<'\n';
    return 0;
}