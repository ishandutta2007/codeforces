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
const int N=20;
int l[N],r[N];
vector<int> solve(vector<int> a,string s){
    int n=sz(a);
    if(sz(a)==1){
        if(s.empty())return a;
        return {};
    }
    for(int x=n/2;x<=min(n-1,sz(s));++x){
        int y=sz(s)-x;
        string t=s.substr(y);
        vector<int> al,ar;
        int pos=0;
        int ok=1;
        forn(i,x){
            if(t[i]=='0')al.pb(a[pos++]);
            else ar.pb(a[pos++]);
            if((sz(al)==n/2||sz(ar)==n/2)&&i!=x-1)ok=0;
        }
        if(!ok)continue;
        if(sz(al)!=n/2&&sz(ar)!=n/2)continue;
        while(sz(al)<n/2)al.pb(a[pos++]);
        while(sz(ar)<n/2)ar.pb(a[pos++]);
        for(int yl=l[n/2];yl<=r[n/2];++yl){
            int yr=y-yl;
            if(yr<l[n/2]||yr>r[n/2])continue;
            vector<int> resl=solve(al,s.substr(0,yl));
            vector<int> resr=solve(ar,s.substr(yl,yr));
            if(resl.empty()||resr.empty())continue;
            for(int i:resr)resl.pb(i);
            return resl;
        }
    }
    return {};
}
int32_t main(){
    for(int i=0;i<=4;++i){
        int n=1<<i;
        l[n]=i*(n/2);
        r[n]=n*(i-1)+1;
    }
    string s;
    cin>>s;
    vector<int> a(16);
    iota(a.begin(), a.end(),1);
    auto v=solve(a,s);
    cout<<sz(v)<<'\n';
    for(int i:v)cout<<i<<' ';
    cout<<'\n';
    return 0;
}