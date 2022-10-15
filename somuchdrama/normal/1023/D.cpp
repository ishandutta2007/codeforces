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

const int N=2e5+5;
// 1-indexed
template <class T=int>
struct fenwick_tree {
    int n;
    T E;
    vector<T> tree;
    fenwick_tree(int _n, T _E = T()) : n(_n), E(_E) {
        tree.assign(n + 1, E);
    }
    fenwick_tree(const vector<T> & a, T _E = T()) : n((int)a.size()), E(_E) {
        tree.assign(n + 1, E);
        for (int i = 0; i < n; ++i)
            add(i + 1, a[i]);
    }
    inline T get(int i) {
        T res = E;
        for (; i; i -= i & -i)
            res += tree[i];
        return res;
    }
    inline void add(int i, T x) {
        for (; i <= n; i += i &-i) 
            tree[i] += x;
    }
    inline T get(int l, int r) { // [l..r]
        return get(r)- get(l - 1);
    }
};
int a[N];
int ft[N];
int lt[N];
int mn[N],mx[N];
vector<int> w[N];
int32_t main() {
    int n,q;
    cin>>n>>q;
    int l=-1;
    for(int i=1;i<=n;++i){cin>>a[i];
        if(a[i]){l=i;}
    }

    for(int i=1;i<=q;++i){
        ft[i]=n+1;
        lt[i]=0;
    }

    if(l==-1){
        cout<<"YES\n";
        for(int i=1;i<=n;++i)
            cout<<q<<' ';
        cout<<'\n';
        return 0;
    }
    int ul=0,w0=-1;
    for(int i = 1;i<=n;++i) {
        if (!a[i]) w0=i;
        if (a[i]==q) ul=1;
    }
    if (!ul){
        if (w0==-1) {
            cout<<"NO\n";
            return 0;
        } else {
            a[w0]=q;
            if (w0>l)l=w0;
        }
    }
    int last=a[l];
    for (int i = n; i >= 1; --i) {
        if (!a[i]) a[i]=last;
        else last=a[i];
    }
    for (int i = 1; i<=n;++i){
        if (ft[a[i]]==n+1) ft[a[i]]=i;
        w[a[i]].pb(i);
    }
    for (int i = n; i>=1;--i){
        if (lt[a[i]]==0) lt[a[i]]=i;
    }
    fenwick_tree open(n+1);
    fenwick_tree close(n+1);
    for (int i = q; i>=1;--i){
        if (!w[i].empty()) {
            for (int j : w[i]) {
                int c1=open.get(j);
                int c2=close.get(j);
                if (c1^c2){
                    cout <<"NO\n";
                    return 0;
                }
            }
            open.add(ft[i],1);
            close.add(lt[i],1);
        }
    }
    cout<<"YES\n";
    for(int i =1;i<=n;++i)
    cout<<a[i]<<' ';
    cout<<'\n';

    return 0;
}