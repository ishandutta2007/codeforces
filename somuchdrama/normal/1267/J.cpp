#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
#else
#define dbg(...)
#endif
struct init{init(){
#ifdef LOCAL
freopen("input.txt","r",stdin);
#endif // LOCAL
cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

const int N=2e6+6;
int a[N],c[N];


int32_t main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        forn(i,n+1)c[i]=0;
        forn(i,n){
            cin>>a[i];
            c[a[i]]++;
        }
        int mn=0;
        vector<int> v;
        forn(i,n+1){
            upx(mn,c[i]);
            if(c[i])v.pb(c[i]);
        }
        int ans=n;
        for(int s=1;s<=mn+1;++s){
            int m=0;
            int ok=1;
            for(int i:v){
                if(i%s==0)m+=(i/s);
                else if(i/s+i%s>=s-1)m+=(i+s-1)/s;
                else{ok=0;break;}
            }
            if(ok)upn(ans,m);
        }
        cout<<ans<<'\n';
    }

    return 0;
}