// Jump, and you will find out how to unfold your wings as you fall.

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

pii p[maxn];
multiset<int>ms;
ll Sum;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
	cin>>p[i].S>>p[i].F;
    }
    sort(p,p+n);
    ll ans=0;
    for(int i=n-1;i>=0;i--){
	Sum+=p[i].S;
	ms.insert(p[i].S);
	if(sz(ms)>k){
	    Sum-=*ms.begin();
	    ms.erase(ms.begin());
	}
	ans=max(ans,Sum*p[i].F);
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.