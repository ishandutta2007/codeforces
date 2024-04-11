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

const int N=1010,C=1e6+6;
int b[N];
void no(){
    cout<<"NO\n";
    exit(0);
}
vector<int> v[2];

int n,sum=0;
vector<int> o;
unordered_map<int, vector<int>> mp;
void yes(vector<int> u){
    cout<<"YES\n";
    int val=0;
    forn(i,sz(u)){
        forn(j,2){
            cout<<val<<' ';
            if(j)val=b[o[i]]-val;
            else val=b[u[i]]-val;
        }
    }
    set<int> us;
    forn(i,sz(o)){
        us.insert(o[i]);
        us.insert(u[i]);
    }
    forn(i,n){
        if(us.count(i))continue;
        cout<<b[i]<<' ';
    }
    cout<<'\n';
    exit(0);
}

void gen(int k,int i){
    if(sz(o)==k){
        if(mp.find(sum)==mp.end()){
            mp[sum]=o;
        }else{
            yes(mp[sum]);
        }
        return;
    }
    if(i==n)return;
    int r=n-i,need=k-sz(o);
    o.pb(i);
    sum+=b[i];
    gen(k,i+1);
    o.pop_back();
    sum-=b[i];
    if(n-i-1>=k-sz(o))gen(k,i+1);
}

int32_t main(){
    cin>>n;
    forn(i,n){
        cin>>b[i];
    }
    sort(b,b+n);
    if(n==2){
        if(b[0]!=b[1])no();
        cout<<"YES\n0 "<<b[0]<<'\n';
        return 0;
    }
    forn(i,n){
        v[b[i]%2].pb(i);
    }
    vector<int> f;
    if(sz(v[0])>=3){
        forn(i,3)
            f.pb(v[0][i]);
    }else if(sz(v[1])>=2&&sz(v[0])>=1){
        f.pb(v[0][0]);
        f.pb(v[1][0]);
        f.pb(v[1][1]);
    }else{
        for(int i=1;i<=n;++i){
            mp.clear();
            gen(i,0);
        }
        no();
    }
    int s=0;
    forn(i,3)s+=b[f[i]];
    s/=2;
    cout<<"YES\n";
    int val=s-b[f[0]];
    forn(i,3){
        cout<<s-b[f[i]]<<' ';
    }
    forn(i,n){
        int ok=1;
        for(int j:f)ok&=j!=i;
        if(!ok)continue;
        cout<<b[i]-val<<' ';
    }
    cout<<'\n';

    return 0;
}