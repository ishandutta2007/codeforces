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
const int N=3e5+5;
int a[N];
int u[N];
int f(){
    int x=0;while(u[x])x++;return x;
}
vector<int> ans;
void h(int i,int x){
    u[a[i]]--;
    a[i]=x;
    u[a[i]]++;
    ans.pb(i+1);
}
int q[N];
int32_t main(){
    int t=1000;
    cin>>t;
    while(t--){
        // int n=rng()%200+1;
        int n;
        cin>>n;
        forn(i,n+1)u[i]=0;
        forn(i,n){
            cin>>a[i];
            // a[i]=rng()%(n+1);
            u[a[i]]++;
        }
        ans.clear();
        int x=f();
        while(x^n){
            h(x,x);
            x=f();
        }
        forn(i,n)q[i]=0;
        // forn(i,n)dbg(a[i]);
        forn(i,n){
            if(!q[i]){
                if(a[i]!=i){
                    int v=i;
                    do{
                        // dbg(v);
                        q[v]=1;
                        int to=a[v];
                        h(v,x);
                        v=to;
                        x=f();
                    }while(!q[v]);
                    h(v,x);
                    x=f();
                }
            }
        }
        // dbg("--");
        // forn(i,n)dbg(a[i]);
        // dbg("==");
        assert(sz(ans)<=n+n);
        cout<<sz(ans)<<'\n';
        for(int i:ans)cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}