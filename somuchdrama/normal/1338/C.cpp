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

int ga(int x){
    int s=1;
    while(x>=s){
        x-=s;
        s*=4;
    }
    return s+x;
}
int kek(int i){
    if(i==0)return 0;
    if(i==1)return 2;
    if(i==2)return 3;
    return 1;
}
int gb(int x){
    int t=2,s=1,p=0;
    while(x>=s){
        x-=s;
        s*=4;
        t*=4;
        p+=2;
    }
    int res=t;
    int st=1;
    forn(i,p){
        int d=x&3;
        res+=st*kek(d);
        x/=4;
        st*=4;
    }
    return res;
}
int solve(int n){
    if(n%3==0){
        int a=ga(n/3-1);
        int b=gb(n/3-1);
        return (a^b);
    }else if(n%3==1)return ga(n/3);
    else return gb(n/3);
}
int32_t main(){

    // vector<int> v={-1};
    // set<int> s;
    // forn(it,40){
    //     for(int a=1;a<=5000;++a){
    //         if(s.count(a))continue;
    //         for(int b=a+1;b<=5000;++b){
    //             if(s.count(b))continue;
    //             int c=a^b;
    //             if(s.count(c))continue;
    //             dbg(a,bitset<7>(a));
    //             dbg(b,bitset<7>(b));
    //             dbg(c,bitset<7>(c));
    //             s.insert(a);
    //             s.insert(b);
    //             s.insert(c);
    //             v.pb(a);
    //             v.pb(b);
    //             v.pb(c);
    //             goto fl;
    //         }
    //     }
    //     fl:;
    // }
    // for(int i=1;i<sz(v);++i){
    //     dbg(i,solve(i),v[i]);
    //     assert(solve(i)==v[i]);
    // }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<'\n';
    }

    return 0;
}