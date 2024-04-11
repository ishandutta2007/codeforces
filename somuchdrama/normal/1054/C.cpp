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
#define int ll

const int N=1001;
int l[N],r[N];
void no(){
    cout<<"NO\n";exit(0);
}
int a[N];
int32_t main() {

    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>l[i];
    for(int i=1;i<=n;++i)cin>>r[i];

    for(int i=1;i<=n;++i){
        a[i]=n-l[i]-r[i];
        if(a[i]<1)no();
    }

    for(int i=1;i<=n;++i){
        int c=0;
        for(int j=1;j<i;++j)if(a[j]>a[i])c++;
        if(c^l[i])no();
        c=0;
        for(int j=i+1;j<=n;++j)if(a[j]>a[i])c++;
        if(c^r[i])no();
    }

    cout<<"YES\n";
    for(int i=1;i<=n;++i)cout<<a[i]<<' ';
        cout<<'\n';


    return 0;
}