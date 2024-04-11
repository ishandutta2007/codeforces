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

ll vall[maxn],valr[maxn],x,sm[maxn],a[maxn];
int n;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>x;
    for(int i=0;i<n;i++){
	cin>>a[i];
	sm[i+1]=sm[i]+a[i];
    }
    ll num=0,ans=0;
    for(int i=0;i<n;i++){
	vall[i]=num-x*sm[i];
	num=max(ll(0),a[i]+num);
	ans=max(ans,num);
    }
    num=0;
    for(int i=n;i>0;i--){
	num=max(ll(0),a[i]+num);
	valr[i]=num+x*sm[i];
    }
    ll mx=vall[0];
    for(int i=1;i<=n;i++){
	ans=max(ans,mx+valr[i]);
	mx=max(mx,vall[i]);
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.