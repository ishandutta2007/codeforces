#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
#else
#define dbg(...) 
#endif
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};


int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a,b;
        int mx=0;
        forn(i,n){
            int x;
            cin>>x;
            if(x<0)a.pb(-x);
            if(x>0)b.pb(x);
            upx(mx,abs(x));
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans=0;
        for(int i=sz(a)-1;i>=0;i-=k){
            ans+=a[i]*2;
        }
        for(int i=sz(b)-1;i>=0;i-=k){
            ans+=b[i]*2;
        }
        ans-=mx;
        cout<<ans<<'\n';
    }
    return 0;
}