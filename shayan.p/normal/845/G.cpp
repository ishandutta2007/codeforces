// High above the clouds there is a rainbow...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define hb(x) (31-__builtin_clz(x))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>vec;
vector<pii>v[maxn];
bool mark[maxn];
int val[maxn],bt[33];

void add(int x){
    for(int y:vec){
	if(bit(x,hb(y))) x^=y;
    }
    if(x==0) return;
    for(int &y:vec){
	if(bit(y,hb(x))) y^=x;
    }
    vec.PB(x);
}

void dfs(int u){
    mark[u]=1;
    for(pii p:v[u]){
	if(mark[p.F]) add(val[u] ^ val[p.F] ^ p.S);
	else val[p.F]=val[u]^p.S, dfs(p.F);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    while(m--){
	int a,b,c;cin>>a>>b>>c;
	v[a].PB({b,c});
	v[b].PB({a,c});
    }
    dfs(1);
    int ans=val[n];
    for(int x:vec){
	bt[hb(x)]=x;
    }
    for(int i=30;i>=0;i--){
	if(bit(ans,i) && bt[i]!=0) ans^=bt[i];
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.