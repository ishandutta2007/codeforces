#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define f first
#define s second
#define pb emplace_back
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;

bool ask(int x1, int y1, int x2, int y2){
    cout<<"? "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<std::endl;
    string res;
    cin>> res;
    return res=="YES";
}

int32_t main() {
    
    int n;
    cin >> n;
    string ans1;
    int x=1,y=0;
    for (++y; x+y<=n+1; ++y) {
        // if(y!=1)
        for (++x;x+y<=n+1;++x){
            if (!ask(x,y,n,n))break;
            ans1+='D';
        }
        --x;
        if(x+y<=n)
        ans1+='R';
    }
    --y;
    // dbg(ans1);
    string ans2;
    int x2=n+1,y2=n;
    for (--x2; y2+x2>=n+1; --x2){
        ans2+='D';
        for(--y2;x2+y2>=n+1;--y2){
            if(!ask(1,1,x2,y2)) {break;}
            ans2+='R';
        }
        ++y2;
    }
    ++x2;

    reverse(ans2.begin(), ans2.end());
    ans2.pop_back();

    // assert(x==y2&&y==x2);

    cout<<"! "<<ans1<<ans2<<std::endl;

    return 0;
}