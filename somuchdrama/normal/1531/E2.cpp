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
const int N=2020;
struct rec{
    int l,r,ls,rs;
};
vector<rec> v;
int f(int n){
    if(n>1){
        int l=n/2,r=n-l;
        int ls=f(l);
        int rs=f(r);
        v.push_back({l,r,ls,rs});
        return ls+rs+1;
    }
    return 0;
}
vector<int> a;
vector<int> psum;
string s;
vector<int> solve(vector<int> p,int ind){
    int n=sz(p);
    if(n==1)return p;
    rec it=v[ind];
    vector<int> al,ar;
    al.reserve(it.l);
    ar.reserve(it.r);
    int pos=0;
    for(int i=psum[ind]-a[ind];i<psum[ind];++i){
        if(s[i]=='0')al.pb(p[pos++]);
        else ar.pb(p[pos++]);
    }
    assert(sz(al)==it.l||sz(ar)==it.r);
    while(sz(al)<it.l)al.pb(p[pos++]);
    while(sz(ar)<it.r)ar.pb(p[pos++]);
    auto resl=solve(al,ind-1-it.rs);
    auto resr=solve(ar,ind-1);
    for(int i:resr)resl.pb(i);
    return resl;
}
int32_t main(){
    cin>>s;
    for(int n=1;n<=1000;++n){
        v.clear();
        a.clear();
        f(n);
        int m=sz(v);
        int cl=0,cr=0,pos=0,ok=1,l=-1;
        forn(i,sz(s)){
            if(s[i]=='0')cl++;
            else cr++;
            if(pos==m){ok=0;break;}
            if(cl==v[pos].l||cr==v[pos].r){
                cl=0;
                cr=0;
                pos++;
                a.pb(i-l);
                l=i;
            }
        }
        psum.resize(m);
        partial_sum(a.begin(), a.end(), psum.begin());
        if(pos!=m)ok=0;
        if(ok){
            vector<int> p(n);
            iota(p.begin(), p.end(), 1);
            auto ans=solve(p,m-1);
            cout<<n<<'\n';
            for(int i:ans)cout<<i<<' ';
            cout<<'\n';
            break;
        }
    }
    return 0;
}