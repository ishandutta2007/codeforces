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
const int N=7777;
int a[N],b[N],u[N];
int cnt[N];

int32_t main(){
    int n;
    cin>>n;
    forn(i,n)cin>>a[i];
    forn(i,n)cin>>b[i];
    int ans=0;
    int sum=0,mx=0,wmx=0;
    forn(i,n){
        ans++;
        sum+=b[i];
        forn(j,n){
            int ot=a[j]&a[i];
            if(a[i]!=a[j]&&ot!=a[i]){
                cnt[i]++;
            }
        }
        dbg(i,cnt[i]);
        if(mx<cnt[i]){
            mx=cnt[i];
            wmx=i;
        }
    }
    dbg(mx,ans);
    while(ans&&mx>=ans-1){
        int v=wmx;
        dbg(v,mx);
        u[v]=1;
        sum-=b[v];
        ans--;
        forn(i,n){
            if(!u[i]){
                int ot=a[v]&a[i];
                if(a[i]!=a[v]&&ot!=a[i]){
                    cnt[i]--;
                }
            }
        }
        mx=0,wmx=0;
        forn(i,n){
            if(u[i])continue;
            if(cnt[i]>mx){
                mx=cnt[i];
                wmx=i;
            }
        }
    }
    if(ans>=2){
        cout<<sum<<'\n';
    }else{
        cout<<"0\n";
    }


    return 0;
}