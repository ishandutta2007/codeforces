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
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
#else
#define dbg(...)
#endif
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
mt19937 rng(300);

const int N=201010;
pair<int,char> a[N];
void go(int &l,int &r,int len){
    cout<<a[r].f<<' '<<a[r].s<<'\n';
    r++;
    forn(i,len-1){
        cout<<a[l].f<<' '<<a[l].s<<'\n';
        l--;
    }
}
int32_t main(){
    int n;
    cin>>n;
    forn(i,n)cin>>a[i].f;
    sort(a,a+n);
    string s;
    cin>>s;
    a[n-1].s=s[n-1];
    for(int i=n-2;i>=0;--i){
        if(a[i+1].s=='R')a[i].s='L';
        else a[i].s='R';
    }
    int h=1;
    forn(i,n-1)h+=s[i]!=s[i+1];
    int l=n-h-1,r=n-h;
    int f=0;
    forn(i,n){
        if(s[i]!=s[f]){
            go(l,r,i-f);
            f=i;
        }
    }
    go(l,r,n-f);
    return 0;
}