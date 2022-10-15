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

const int32_t M=998244353;
int32_t rev(int32_t x,int32_t m){
    if(x==1)return 1;
    return (1-(ll)rev(m%x,x)*m)/x+m;
}
struct mint{
    int32_t x;
    mint():x(0){}
    mint(int32_t xx):x(xx%M){if(x<0)x+=M;}
    mint(ll xx):x(xx%M){if(x<0)x+=M;}
    mint& operator+=(mint b){if((x+=b.x)>=M)x-=M;return *this;}
    mint operator+(mint b){mint res=*this;res+=b;return res;}
    mint& operator-=(mint b){if((x-=b.x)<0)x+=M;return *this;}
    mint operator-(mint b){mint res=*this;res-=b;return res;}
    mint& operator*=(mint b){x=(ll)x*b.x%M;return *this;}
    mint operator*(mint b){mint res=*this;res*=b;return res;}
    mint inverse(){return rev(x,M);}
    mint& operator/=(mint b){x=(ll)x*rev(b.x,M)%M;return *this;}
    mint operator/(mint b){mint res=*this;res/=b;return res;}
    mint operator^(ll w) {mint r=1,a=*this;while(w){if(w&1)r*=a;a*=a;w/=2;}return r;}
    mint operator^=(ll w){return *this=(*this)^w;}
    mint operator^(mint w){return *this^w.x;}
    mint operator^=(mint w){return *this=(*this)^w;}
    mint operator-()const{return mint()-*this;}
    explicit operator bool()const{return x;}
};
istream&operator>>(istream&is,mint&p){istream&res=is>>p.x;p.x%=M;return res;}
ostream&operator<<(ostream&os,mint p){return os<<p.x;}
template<typename T>mint operator+(T x,mint y){return mint(x)+y;}
template<typename T>mint operator-(T x,mint y){return mint(x)-y;}
template<typename T>mint operator*(T x,mint y){return mint(x)*y;}
template<typename T>mint operator/(T x,mint y){return mint(x)/y;}
template<typename T>mint operator^(T x,mint y){return mint(x)^y;}
mint abs(mint x){return x;}
const int N=505050;
struct md{
    mint a,b;
    bool f;
}mod[N*4];
mint t[N*4],len[N*4];

int sh=1;
void apply(int v,md m){
    if(m.f){
        t[v]=m.b*len[v];
        mod[v]=m;
    }else{
        (t[v]*=m.a)+=m.b*len[v]; //<--
        mod[v].a*=m.a;
        (mod[v].b*=m.a)+=m.b;
    }
}
void push(int v){
    apply(v+v,mod[v]);
    apply(v+v+1,mod[v]);
    mod[v]={1,0,0};
}
void recalc(int v){
    t[v]=t[v+v]+t[v+v+1]; //<--
}
int a[N];
int al[N];
void build(int n){
    while(sh<n)sh*=2;
    forn(i,sh+sh)t[i]=0;//<--
    forn(i,sh+sh)mod[i]={1,0,0};//<--
    forn(i,n){
        len[i+sh]=al[i];
        if(i)len[i+sh]-=al[i-1];
    }
    for(int i=sh-1;i>0;--i)len[i]=len[i+i]+len[i+i+1];
}
int l,r;
md m;
void upd(int v,int tl,int tr){
    if(l<=tl&&tr<=r){
        apply(v,m);
        return;
    }
    push(v);
    int tm=(tl+tr)/2;
    if(tm>=l)upd(v+v,tl,tm);
    if(tm+1<=r)upd(v+v+1,tm+1,tr);
    recalc(v);
}
void upd(int _l,int _r,md _m){
    if(_l>_r)return;
    l=_l,r=_r,m=_m;
    upd(1,0,sh-1);
}

int32_t main(){

    int n;
    cin>>n;
    forn(i,n){
        cin>>a[i];
        al[i]=a[i];
    }
    sort(al,al+n);
    int m=unique(al,al+n)-al;
    build(m);
    int ap=lower_bound(al,al+m,a[0])-al;
    upd(0,ap,md{0,1,1});
    for(int i=1;i<n;++i){
        int ai=lower_bound(al,al+m,a[i])-al;
        mint tot=t[1];
        upd(0,ai,md{-1,tot,0});
        upd(ai+1,sh-1,md{0,0,0});
        ap=ai;
    }
    cout<<t[1]<<'\n';

    return 0;
}