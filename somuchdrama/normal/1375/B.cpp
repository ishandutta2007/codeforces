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
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};
const int N=333;
int a[N][N];
int n,m;
int kok(int x,int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int ok=1;
        forn(i,n)forn(j,m){
            cin>>a[i][j];
            int c=0;
            forn(d,4){
                int ti=i+dx[d],tj=j+dy[d];
                if(kok(ti,tj))c++;
            }
            if(a[i][j]>c)ok=0;
            a[i][j]=c;
        }
        if(!ok){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            forn(i,n){
                forn(j,m)cout<<a[i][j]<<' ';
                cout<<'\n';
            }
        }
    }
    return 0;
}