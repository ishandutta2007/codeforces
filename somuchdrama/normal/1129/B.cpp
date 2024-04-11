#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define f first
#define s second
#define pb emplace_back
#define sz(a) ((int)a.size())
#define forn(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
#define int ll

int32_t main() {
    int k;
    cin>>k;
    for(int a=1;a<=2000;++a){
        for(int b=1;a+b<=2000;++b){
            if((k+a+b)%a==0){
                int s=(k+b+a)/a;
                if(b*1000000>=s){
                    int n=a+b;
                    cout<<n<<'\n';
                    forn(i,a-1)cout<<"0 ";
                    cout<<"-1 ";
                    for(int j=a;j<n;++j){
                        int p=min(s,1000000ll);
                        cout<<p<<' ';
                        s-=p;
                    }
                    cout<<'\n';
                    return 0;
                }
            }
        }
    }
    // forn(i,100000){
    //     k=rand()%1000000000+1;
    //     bool ok=0;
    //     for(int a=1;!ok&&a<=2000;++a){
    //         for(int b=1;!ok&&a+b<=2000;++b){
    //             if((k+a+b)%a==0){
    //                 int s=(k+b+a)/a;
    //                 if(b*1000000>=s){
    //                     ok=1;
    //                     // dbg(k,a,b);
    //                 }
    //             }
    //         }
    //     }
    //     if(!ok)dbg("!!!",k);
    // }
    cout<<"-1\n";

    return 0;
}