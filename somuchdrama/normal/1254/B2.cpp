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

const int N=1e6+6;
int a[N];
int b[N];
int ans=1e18;
int n;
int s=0;
void check(int x){
    forn(i,n)a[i]=b[i]%x;
    int cur=0;
    int p=0;
    int pv=0;
    int pos=-1;
    forn(i,n){
        p+=a[i];
        if(p+p>=x&&pos==-1){
            pos=i;
            for(int j=pv;j<i;++j)cur+=a[j]*(i-j);
        }
        if(p>=x){
            p-=a[i];
            int tak=x-p;
            a[i]-=tak;
            cur+=tak*(i-pos);
            p=a[i];
            pv=i;
            pos=-1;
        }
        if(pos!=-1){
            cur+=a[i]*(i-pos);
        }
        if(p+p>=x&&pos==-1){
            pos=i;
            for(int j=pv;j<i;++j)cur+=a[j]*(i-j);
        }
    }
    dbg(x,cur);
    upn(ans,cur);
}
int32_t main(){
    cin>>n;
    forn(i,n){
        cin>>b[i];
        s+=b[i];
    }
    if(s==1){
        cout<<"-1\n";
        return 0;
    }
    int se=s;
    for(int x=2;x*x<=se;++x){
        if(se%x==0){
            check(x);
            while(se%x==0)se/=x;
        }
    }
    if(se^1)check(se);
    cout<<ans<<'\n';
    return 0;
}