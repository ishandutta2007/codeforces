// Faster!

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

int m,a,b,ans[maxn],f[maxn];
bool mark[maxn];

void dfs(int u,int lim,int &num){
    num++;
    mark[u]=1;
    if(u-b>=0 && mark[u-b]==0) dfs(u-b,lim,num);
    if(u+a<=lim && mark[u+a]==0) dfs(u+a,lim,num);
}

ll calc(int n,int g){
    int n0=(n/g)*g;
    int x=n/g;
    ll ans=1ll*((1ll*x*(x-1))/2)*g;
    for(int i=n0;i<=n;i++) ans+=i/g;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>m>>a>>b;
    mark[0]=1;
    f[0]=1;
    int g=__gcd(a,b);
    int lim=((a+b+g-1)/g)*g;
    for(int i=1;i<=lim;i++){
	f[i]=f[i-1];
	if(i>=a && mark[i-a]) dfs(i,i,f[i]);
    }
    ll ans=0;
    for(int i=0;i<=min(lim,m);i++){
	ans+=f[i];
    }
    if(m<=lim) return cout<<ans<<endl,0;
    ans+=calc(m,g)+m-calc(lim,g)-lim;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.