
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.be,x.ee
#define le (x*2)
#define ri (x*2+1)
#define mid ((l+r)/2)
#define ld long double
#define e '\n'
#define sp ' '
#define pb push_back
#define pf push_front
#define up upper_bound
#define lo lower_bound
#define in insert
#define mk make_pair
#define er erase
#define R return
#define se second
#define co continue
#define fi first
#define fr front()
#define ba back()
#define si size()
#define em empty()
#define be begin()
#define ee end()
#define ep 0.0000001
#define pi acos(-1)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int32_t mod=1e9+7, m1=1e9+123, m2=1e9+321;
static const int base=uniform_int_distribution<int>(300,(int)1e9+122)(rng);
static inline int add(int a,int b,int Mod) {
    R ((ll)a+b)%Mod;
}
static inline int sub(int a,int b,int Mod) {
    R (((ll)a-b)%Mod+Mod)%Mod;
}
static inline int mul(int a,int b,int Mod){
    R 1ll*a*b%Mod;
}

int n,d[100100],p[100100][20];
ll arr[100100],g[100100][20];
vi v[100100];
bool vis[100100];
void dfs(int i,int l,int pre){
    vis[i]=1;
    g[i][0]=__gcd(arr[pre],arr[i]);
    p[i][0]=pre;
    d[i]=l;
    for(int j=0;j<v[i].si;j++){
        if(!vis[v[i][j]]) dfs(v[i][j],l+1,i);
    }
}
int query(int i){
    if(i==1) R arr[i]%mod;
    int ret=0, x=log2(d[i]);
    ll cur=arr[i];
    for(int k=0;k<10000;k++){
        int cnt=1;
        for(int j=x;j>=0&&i!=1;j--){
            if (p[i][j]==0)continue;
            if(__gcd(g[i][j],cur)==cur) i=p[i][j], cnt+=(1<<j);
        }
        ret=add(ret,mul(cnt,cur%mod,mod),mod);
        if(i==1) break;
        i=p[i][0];
        x=log2(d[i]);
        cur=__gcd(cur,arr[i]);
    }
    R ret;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,0,0);
    for(int j=1;j<=log2(n);j++){
        for(int i=1;i<=n;i++) p[i][j]=p[p[i][j-1]][j-1];
    }
    for(int j=1;j<=log2(n);j++){
        for(int i=1;i<=n;i++) g[i][j]=__gcd(g[i][j-1],g[p[i][j-1]][j-1]);
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=add(ans,query(i),mod);
    printf("%d\n",ans);
    R 0;
}