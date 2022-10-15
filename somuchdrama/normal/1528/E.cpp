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

const int N=1e6+6;
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
mint i2,i6;
mint c3(mint p){
    return (1)+(p)+(p*(p-1)*i2+p)+(p+p*(p-1)+p*(p-1)*(p-2)*i6);
}
mint c2(mint p){
    return (1)+(p)+(p*(p-1)*i2+p);
}
mint f[N],p[N];
int32_t main(){
	int n;
	cin>>n;
    f[0]=1;
    i2=mint(1)/2;
    i6=mint(1)/6;
    for(int i=1;i<n;++i)f[i]=c2(f[i-1]);
    // forn(i,n)dbg(i,f[i]);
    mint q=c3(f[n-1])-(n>1?c3(f[n-2]):1);
    dbg(q);
    mint ans=q;
    dbg(ans);
    mint qq=q;
    qq-=f[n-1]-(n>1?f[n-2]:0);
    ans+=qq;
    dbg(qq,ans);
    for(int i=1;i<n;++i){
        int eup=i,edown=n-i-1;
        mint up=f[eup-1]*(f[eup-1]+1)*i2;
        if(eup-2>=0){
            // dbg("big eup");
            up-=f[eup-2]*(f[eup-2]+1)*i2;
        }else{
            //hz
        }
        mint down=f[edown];
        if(edown>0){
            down-=f[edown-1];
        }
        // dbg(i,eup,up,edown,down);
        ans+=up*down;
    }
    cout<<ans<<'\n';
    // mint cur=1;
    // forn(i,n){
    //     if(i){
    //         mint w=1+f[i-1];
    //         if(i==n-1)w+=f[i-1]*(f[i-1]+1)*i2;
    //         cur*=w;
    //     }
    //     p[i]=cur;
    //     dbg(i,p[i]);
    // }
    // mint ans=p[n-1];
    // dbg(ans);
    // for(int i=1;i<n;++i){
    //     mint w=f[i-1];
    //     if(i==n-1)w+=f[i-1]*(f[i-1]+1)*i2;
    //     mint c=p[i-1]*w;
    //     if(i+1<n)c*=p[n-i-2];
    //     dbg(i,c);
    //     ans+=c;
    // }
    // return ans;
    // cout<<solve(n)-solve(n-1)<<'\n';
    return 0;
}