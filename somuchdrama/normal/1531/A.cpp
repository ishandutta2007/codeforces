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


vector<string> cols={"red","orange","yellow","green","blue","indigo","violet"};
struct state{
    int loc,col;
};
struct op{
    state t[2];
    op(){
        forn(i,2)t[i].loc=t[i].col=0;
    }
    op(string s){
        if(int pos=find(cols.begin(),cols.end(),s)-cols.begin();pos!=sz(cols)){
            t[0].loc=0;
            t[0].col=pos+1;
            t[1].loc=1;
            t[1].col=0;
        }else if(s=="lock"){
            t[0].loc=t[1].loc=1;
            t[0].col=t[1].col=0;
        }else{
            t[0].loc=t[1].loc=t[0].col=t[1].col=0;
        }
    }
};
state apply(state p,op o){
    if(int c=o.t[p.loc].col;c)p.col=c;
    p.loc=o.t[p.loc].loc;
    return p;
}
op operator +(op a,op b){
    op c;
    forn(i,2)c.t[i]=apply(apply(state{i,0},a),b);
    return c;
}
const int N=101010;
op a[N];
op t[N*4];
int s=1;
void build(int n){
    while(s<n)s*=2;
    forn(i,n)t[i+s]=a[i];
    for(int i=s;--i;)t[i]=t[i+i]+t[i+i+1];
}
void upd(int i,op val){for(t[i+=s]=val;i/=2;)t[i]=t[i+i]+t[i+i+1];}
void pt(){
    state start{0,5};
    start=apply(start,t[1]);
    cout<<cols[start.col-1]<<'\n';
}
int32_t main(){
    int n,q;
    cin>>n;
    forn(i,n){
        string w;
        cin>>w;
        a[i]=op(w);
    }
    build(n);
    pt();
    return 0;
}