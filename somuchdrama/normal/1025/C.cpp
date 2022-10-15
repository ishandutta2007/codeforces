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

string op(string s, int i){
    string t;
    for(int j=i-1;j>=0;--j)
        t+=s[j];
    int n=s.size();
    for(int k=0,j=n-1;k<n-i;++k,--j)
        t+=s[j];
    return t;
}
int zebra(string s){
    int w=0,b=0;
    int x=0;
    for (char c:s){
        if(c=='w'){w=b+1;b=0;}
        else {b=w+1;w=0;}
        x=max(x,b);
        x=max(x,w);
    }
    return x;
}
const int N=1e5+5;
int wa[N],wb[N],ba[N],bb[N];
int32_t main() {
    string s;
    cin>>s;
    int n=s.size();
    s="#"+s;
    wa[0]=0;
    ba[0]=0;
    int ans=0;
    for(int i=1;i<=n;++i){
        if(s[i]=='w')
            wa[i]=ba[i-1]+1,ba[i]=0;
        else
            ba[i]=wa[i-1]+1,wa[i]=0;
        ans=max(ans,wa[i]);
        ans=max(ans,ba[i]);
    }
    dbg(ans);
    wb[n+1]=0;
    bb[n+1]=0;
    for(int i=n;i>=1;--i){
        if(s[i]=='w')
            wb[i]=bb[i+1]+1,bb[i]=0;
        else
            bb[i]=wb[i+1]+1,wb[i]=0;
    }

    for(int i=1;i<n;++i){
        int len1=i;
        int len2=n-i;
        {
            int val1=min(len1,wb[1]);
            int val2=min(len2,ba[n]);
            int pot=val2+val1;
            ans=max(ans, pot);
        }
        {
            int val1=min(len1,bb[1]);
            int val2=min(len2,wa[n]);
            int pot=val2+val1;
            ans=max(ans, pot);
        }
    }
    cout<<ans<<'\n';

//     int t=100;
//     while (t--){
//         int n = rand()%100+1;
//         string s;
//         for(int i=0;i<n;++i){
//             if(rand()&1) s+='w';
//             else s+='b';
//         }
//         dbg(n, s);
//         set<string> all;
//         all.insert(s);
//         int ans=zebra(s);
//         dbg(n,-1);
//         for(int it=0;it<2;++it){
//             set<string> nw;
//             for(auto i:all){
//                 for(int j=0;j<=n;++j)
//                     nw.insert(op(i,j));
//             }
//             int pot=0;
//             string where;
//             for(auto i:nw){
//                 int val=zebra(i);
//                 if(val>pot){
//                     pot=val;
//                     where=i;
//                 }
//             }
//             all=nw;
//             if(pot>ans){
//                 ans=pot;
//                 assert(it<1);
//                 dbg(n,it,pot,where);
//             }
//         }
//     }


    return 0;
}