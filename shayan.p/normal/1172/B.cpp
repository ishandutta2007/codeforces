// High above the clouds there is a rainbow...

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

const int maxn=2e5+10,mod=998244353;
const ll inf=1e18;

int dg[maxn],fac[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	dg[a]++,dg[b]++;
    }
    fac[0]=1;
    for(int i=1;i<maxn;i++){
	fac[i]=1ll*i*fac[i-1] %mod;
    }
    int ans=n;
    for(int i=1;i<=n;i++){
	ans=1ll*ans*fac[dg[i]] %mod;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.