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

const int N=111;
char f[N][N];
char ans[N][N];
char kek[N];
vector<pii> w[N];
int32_t main(){
    int it=0;
    for(char c='a';c<='z';++c){
        kek[it++]=c;
    }
    for(char c='A';c<='Z';++c){
        kek[it++]=c;
    }
    for(char c='0';c<='9';++c){
        kek[it++]=c;
    }
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        forn(i,k)w[i].clear();
        int c=0;
        forn(i,n)forn(j,m){
            cin>>f[i][j];
            if(f[i][j]=='R')c++;
        }
        int big=(c+k-1)/k;
        int small=big-1;
        int cb=c%k;
        if(cb==0)cb=k;
        int cur=0;
        int kur=0;
        dbg(big,small,cb);
        forn(i,n){
            if(i&1){
                for(int j=m-1;j>=0;--j){
                    if(f[i][j]=='R')cur++;
                    ans[i][j]=kek[kur];
                    w[kur].pb(i,j);
                    if(cb){
                        if(cur==big){
                            if(kur+1<k)kur++,cb--,cur=0;
                        }
                    }else{
                        if(cur==small){
                            if(kur+1<k)kur++,cur=0;
                        }
                    }
                }
            }else{
                for(int j=0;j<m;++j){
                    if(f[i][j]=='R')cur++;
                    ans[i][j]=kek[kur];
                    w[kur].pb(i,j);
                    if(cb){
                        if(cur==big){
                            if(kur+1<k)kur++,cb--,cur=0;
                        }
                    }else{
                        if(cur==small){
                            if(kur+1<k)kur++,cur=0;
                        }
                    }
                }
            }
        }
        if(c<k){
            dbg("yep");
            if(!w[kur].empty())kur++;
            int pos=0;
            while(kur<k){
                if(w[pos].size()>1){
                    int x=w[pos].back().f;
                    int y=w[pos].back().s;
                    ans[x][y]=kek[kur];
                    kur++;
                    w[pos].pop_back();
                }else pos++;
            }
        }
        forn(i,n){
            forn(j,m)cout<<ans[i][j];
            cout<<'\n';
        }
    }

    return 0;
}