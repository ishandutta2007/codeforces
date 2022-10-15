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


int32_t main(){

    string s;
    cin>>s;
    int n=s.size();
    vector<pair<char,int>> a;
    char c=s[0];
    int z=1;
    for(int i=1;i<n;++i){
        if(c==s[i]){
            z++;
        }else{
            a.pb(c,z);
            c=s[i];
            z=1;
        }
    }
    a.pb(c,z);
    int m=a.size();
    int ans=0;
    if(m&1){
        int ok=1;
        forn(i,m/2){
            ok&=a[i].f==a[m-i-1].f;
            ok&=(a[i].s+a[m-i-1].s>=3);
        }
        ok&=a[m/2].s>=2;
        if(ok)ans=a[m/2].s+1;
    }
    cout<<ans<<'\n';

    return 0;
}