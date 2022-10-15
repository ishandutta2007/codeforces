#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
const int N=102,A=10001;
int a[N];
int d1[N][A];
int d2[N][A];

int32_t main() {

    int n;
    cin>>n;
    auto dp=d1,ndp=d2;
    dp[0][0]=1;
    map<int,int> c;
    int sum=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
        c[a[i]]++;
        // for(int w=0;w<=i;++w){
        //     for(int j=0;j<A;++j){
        //         ndp[w][j]=dp[w][j];
        //         if(w&&j>=a[i])ndp[w][j]+=dp[w-1][j-a[i]];
        //         if(ndp[w][j]>2)ndp[w][j]=2;
        //     }
        // }
        // swap(dp,ndp);
    }
    int was=0;
    for(auto&p:c){
        was+=p.s;
        dbg(p.f,p.s);
        for(int w=0;w<=was;++w){
            for(int j=0;j<A;++j){
                ndp[w][j]=dp[w][j];
                for(int f=0;f<=min(w,p.s);++f){
                    if(f&&j>=p.f*f){
                        // if(w==2&&j==7&&f==1){dbg("kek",dp[w-1][j-4],p.f*f,j);}
                        ndp[w][j]+=dp[w-f][j-p.f*f];
                        // if(w==2&&j==7&&f==1){dbg(ndp[w][j]);}

                    }
                    if(ndp[w][j]>2)ndp[w][j]=2;
                }
            }
        }
        swap(dp,ndp);
        dbg(p.f,p.s,dp[1][3]);
        dbg(p.f,p.s,dp[2][7]);
        dbg(p.f,p.s,dp[3][12]);
    }
    // for(int w=0;w<=was;++w)
    //     for(int j=0;j<=sum;++j)
    //         dbg(w,j,dp[w][j]);
    dbg(dp[2][8]);
    int ans=0;
    for(auto&p:c){
        for(int j=1;j<=p.s;++j){
            if(dp[j][j*p.f]==1){
                upx(ans,j);
            }
        }
    }
    if(c.size()==2){
        auto p1=*c.begin(),p2=*c.rbegin();
        if(dp[p1.s][p1.f*p1.s]==1&&dp[p2.s][p2.f*p2.s]==1)ans=n;
    }
    cout<<ans<<'\n';

    return 0;
}