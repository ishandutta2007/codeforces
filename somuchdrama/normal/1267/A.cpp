#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
#else
#define dbg(...)
#endif
struct init{init(){
#ifdef LOCAL
freopen("input.txt","r",stdin);
#endif // LOCAL
cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

const int N=200*1000+17;
int n;
int l[N],r[N],t[N];

int32_t main(){
    cin>>n;
    map<int, vector<pii> > Q;
    set<int> xs;
    forn(i,n){
        cin>>l[i]>>r[i]>>t[i];
        Q[l[i]].pb(pii(1,i));
        Q[r[i]].pb(pii(0,i));
        xs.insert(l[i]);
        xs.insert(r[i]);
    }
    int rx=*std::min_element(l,l+n);
    int ans=0;
    set<pii> T;
    for (const auto& [x,E]:Q){
        dbg(x);
        for(const auto& [tt,i]:E)
            if (tt == 0){
                T.erase(pii(t[i],i));
            }else{
                T.insert(pii(t[i],i));
            }
        rx = max(x,rx);
        while (!T.empty()&&x+T.begin()->f>r[T.begin()->s])
            T.erase(T.begin());
        if(!T.empty()){
            rx=min(rx,x+T.begin()->f);
            auto nx=*xs.upper_bound(x);
            auto tt = max(0ll, nx - rx) / T.begin()->f;
            rx += tt * (T.begin()->f);
            ans += tt;
            if(rx<nx){
                while (!T.empty()&&rx+T.begin()->f>r[T.begin()->s]){
                    if(T.begin()->s==4)dbg("biba",x,rx);
                    T.erase(T.begin());
                }
                if(!T.empty()){
                    ++ans;
                    rx+=T.begin()->f;
                }
            }
        }
        if(x==11)dbg(ans,rx);
    }
    cout<<ans<<'\n';
    return 0;
}