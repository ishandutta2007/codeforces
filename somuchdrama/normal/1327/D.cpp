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

const int N=2e5+5;
int a[N],c[N],u[N];
bool check(vector<int>&w,int s){
    forn(i,s){
        int ok=1;
        for(int j=i+s;j<w.size();j+=s){
            ok&=c[w[j]]==c[w[i]];
        }
        if(ok)return 1;
    }
    return 0;
}

int32_t main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i){
            cin>>c[i];
            u[i]=0;
        }
        int mn=n,ok=0;
        for(int i=1;i<=n;++i){
            if(u[i])continue;
            vector<int> w;
            int v=i,le=0;
            do{
                w.pb(v);
                le++;
                v=a[v];
                u[v]=1;
            }while(v!=i);
            for(int d=1;d*d<=le;++d){
                if(le%d==0){
                    if(check(w,d))upn(mn,d);
                    if(check(w,le/d))upn(mn,le/d);
                }
            }
        }
        if(ok)cout<<"1\n";
        else cout<<mn<<'\n';
    }

    return 0;
}