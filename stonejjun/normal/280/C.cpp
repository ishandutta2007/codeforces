#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;

#define ff first
#define ss secondac
#define eb emplace_back
#define ep emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) lower_bound(all(v), x) - v.begin()
//cout<<fixed;
//cout.precision(12);

struct poi{
    ll val,xx,yy;
};

vector<ll> x;
ll n,m;
ll mod=998244353;
string s;
string t;
ll arr[1010101];
ll chk[1010101];

vector<ll> v[1010101];
ll dep[1010101];
ll vis[1010101];
void dfs(ll x,ll d){
    vis[x]=1;
    dep[x]=d;
    for(auto k:v[x]){
        if(vis[k]) continue;
        dfs(k,d+1);
    }
}

int main(){
   //ios_base::sync_with_stdio(0);
   // cin.tie(0);
    ll i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        ll a,b;
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }

    dfs(1,1);
    dl ans;
    for(i=1;i<=n;i++){
        dl dp=dep[i];
        ans+=(dl)((dl)1/dp);
    }
    printf("%.10f",ans);
}