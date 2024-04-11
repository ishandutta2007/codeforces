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
const int N=202020;
int al[N]; 
pii a[N];
vector<int> v[N];
int k[N];
int32_t main(){
    int n,m=0;
    cin>>n;
    forn(i,n){
        cin>>a[i].f>>a[i].s;
        al[m++]=a[i].f;
        al[m++]=a[i].s;
    }
    sort(al,al+m);
    m=unique(al,al+m)-al;
    map<pii,int> c;
    forn(i,n){
        int x=lower_bound(al,al+m,a[i].f)-al,y=lower_bound(al,al+m,a[i].s)-al;
        if(x==y)k[x]++;
        else{
            if(x<y)swap(x,y);
            c[{x,y}]++;
            v[x].pb(y);
            v[y].pb(x);
        }
    }
    int ans1=0,ans2=0,ans3=0;
    forn(i,m){
        for(int j:v[i]){
            ans1+=sz(v[j])-1;
            ans2+=k[j];
        }
        ans3+=k[i]*(k[i]-1)/2;
    }
    ans1/=2;
    for(auto p:c)ans1-=p.s*(p.s-1)/2;
    cout<<ans1+ans2+ans3<<'\n';
    return 0;
}