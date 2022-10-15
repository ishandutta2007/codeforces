#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
using std::make_pair;
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x)((x)*(x))
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
#define int ll
map<int,int> f;


int32_t main() {

    // for(int it=0;it<=25;++it){
    //     int a=(1<<it)-1;
    //     dbg(a);
    //     for(int b=1;b<a;++b){
    //         int g=std::gcd(a,b);
    //         upx(f[a],g);
    //     }
    // }
    // for(pii p:f){
    //     cout<<"f["<<p.f<<"]="<<p.s<<";\n";
    // }
    f[3]=1;
f[7]=1;
f[15]=5;
f[31]=1;
f[63]=21;
f[127]=1;
f[255]=85;
f[511]=73;
f[1023]=341;
f[2047]=89;
f[4095]=1365;
f[8191]=1;
f[16383]=5461;
f[32767]=4681;
f[65535]=21845;
f[131071]=1;
f[262143]=87381;
f[524287]=1;
f[1048575]=349525;
f[2097151]=299593;
f[4194303]=1398101;
f[8388607]=178481;
f[16777215]=5592405;
f[33554431]=1082401;

    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(f.find(a)!=f.end()){
            cout<<f[a]<<'\n';
        }else{
            for(int it=0;;++it){
                int p=(1<<it)-1;
                if(p>=a){
                    cout<<p<<'\n';
                    break;
                }
            }
        }
    }


    
    return 0;
}