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

int ask(int x,int y){
    cout<<"? "<<x<<' '<<y<<endl;
    int r;cin>>r;
    assert(r!=-1);
    return r;
}
int32_t main(){
    const int m=1e9;
    int a=ask(1,1);
    int b=ask(m,1);
    int sum=m+1-b+a;
    if(sum%2==0){
        int xm=sum/2;
        int yl=ask(xm,1)+1;
        int xl=a+2-yl;
        int xr=xm+(xm-xl);
        int yr=m-ask(xm,m);
        cout<<"! "<<xl<<' '<<yl<<' '<<xr<<' '<<yr<<endl;
    }else{
        int xm=sum/2;
        int yl=ask(xm,1)+1;
        int xl=a+2-yl;
        int xr=xm+(xm-xl)+1;
        int yr=m-ask(xm,m);
        cout<<"! "<<xl<<' '<<yl<<' '<<xr<<' '<<yr<<endl;
    }
    return 0;
}