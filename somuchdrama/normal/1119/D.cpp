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

const int N=1e5+5;
int a[N];
pii qs[N];
int ans[N];
int32_t main() {

    int n,q;
    cin>>n;
    forn(i,n)cin>>a[i];
    sort(a,a+n);
    cin>>q;
    forn(i,q){
        int l,r;
        cin>>l>>r;
        qs[i].f=r-l+1;
        qs[i].s=i;
    }
    sort(qs,qs+q);
    int len=1;
    int res=n;
    std::multiset<int> s;
    s.insert(1e18+123456789);
    for(int i=0;i<n-1;++i){
        if(a[i+1]==a[i])res--;
        if(a[i+1]-a[i]>1)s.insert(a[i+1]-a[i]);
    }
    forn(i,q){
        int gol=qs[i].f;
        while(len<gol){
            int mn=*s.begin();
            if(mn<=gol){
                res+=(mn-len)*(s.size());
                s.erase(mn);
                len=mn;
            }else{
                int dt=gol-len;
                res+=dt*(s.size());
                len=gol;
            }
        }
        ans[qs[i].s]=res;
    }
    forn(i,q)cout<<ans[i]<<' ';
    cout<<'\n';



    return 0;
}