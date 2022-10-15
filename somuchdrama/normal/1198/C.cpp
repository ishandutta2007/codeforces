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

const int N=3e5+5;
vector<pii> g[N];
int c[N];

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n*3;++i){g[i].clear();c[i]=0;}
        forn(i,m){
            int a,b;
            cin>>a>>b;
            g[a].pb(b,i);
            g[b].pb(a,i);
        }
        vector<int> ans;
        int cnt=0;
        for(int i=1;i<=n*3;++i){
            if(ans.size()==n)break;
            if(cnt==n)break;
            int f=1;
            for(pii p:g[i]){
                if(c[p.f]){
                    f=0;
                    c[p.f]=0;
                    cnt--;
                    ans.pb(p.s+1);
                    break;
                }
            }
            if(f){
                c[i]=1;
                cnt++;
            }
        }
        if(ans.size()==n){
            cout<<"Matching\n";
            for(int i:ans)cout<<i<<' ';
        }else{
            cout<<"IndSet\n";
            for(int i=1;i<=n*3;++i)if(c[i])cout<<i<<' ';
        }
        cout<<'\n';
    }

    return 0;
}