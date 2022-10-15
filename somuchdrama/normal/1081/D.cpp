#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define f first
#define s second
#define pb emplace_back
#define fon(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
#define int ll

const int N=1e5+1;
struct edge{
    int a,b,c;
} es[N];

int p[N],rank[N],cnt[N];
int get(int x) {
    return x == p[x] ? x : (p[x] = get(p[x]));
}

bool un(int x, int y) {
    if((x=get(x))==(y=get(y)))return 0;
    if(rank[x]<rank[y]) swap(x, y);
    p[y]=x;
    if(rank[x]==rank[y])rank[x]++;
    cnt[x]+=cnt[y];
    return 1;
}


int32_t main() {

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;++i){
        int x;
        cin>>x;
        cnt[x]=1;
    }
    for(int i=0;i<m;++i)
        cin>>es[i].a>>es[i].b>>es[i].c;
    sort(es,es+m,[](const edge&p1,const edge&p2){
        return p1.c<p2.c;
    });
    for(int i=1;i<=n;++i){
        p[i]=i;
    }
    for(int i=0;i<m;++i){
        dbg(es[i].a,es[i].b,es[i].c);
        if(un(es[i].a,es[i].b)){

            if(cnt[get(es[i].a)]==k){
                for(int j=0;j<k;++j)cout<<es[i].c<<' ';
                cout<<'\n';
                return 0;
            }
        }
    }



    return 0;
}