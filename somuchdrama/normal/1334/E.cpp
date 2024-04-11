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
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};
const int M=998244353;
vector<int> d;
const int C=1e5+15;
int bp(int a,int pw){ 
    int r=1;
    for(;pw;(a*=a)%=M,pw/=2)if(pw&1)(r*=a)%=M;
    return r;
}
int inverse(int a){return bp(a%M,M-2);} 
int fc[C],ifc[C];
struct pc{pc(){
        fc[0]=1;
        for(int i=1;i<C;++i)fc[i]=(fc[i-1]*i)%M;
        ifc[C-1]=inverse(fc[C-1]);
        for(int i=C-2;i>=0;--i)ifc[i]=(ifc[i+1]*(i+1))%M;
}}pc;
int bin(int n,int k){
    if(k<0||k>n)return 0;
    return(((fc[n]*ifc[k])%M)*ifc[n-k])%M;
}
int f(int a,int g){
    if(a==g)return 1;
    int x=a/g,up=0,down=1;
    for(int p:d){
        int c=0;
        while(x%p==0){
            x/=p;
            c++;
        }
        up+=c;
        (down*=ifc[c])%=M;
    }
    up=fc[up];
    return up*down%M;
}
int32_t main(){
    int n;
    cin>>n;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            d.pb(i);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)d.pb(n);
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int g=gcd(a,b);
        cout<<((f(a,g)*f(b,g))%M)<<'\n';
    }
    return 0;
}