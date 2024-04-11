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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
	int n;cin>>n;
	cout<<1<<" "<<n-1<<" ";
	for(int i=1;i<=n;i++) cout<<i<<" ";
	cout<<endl;
	int mx;cin>>mx;
	int l=2,r=n+1;
	while(r-l>1){
	    int mid=(l+r)>>1;
	    cout<<1<<" "<<mid-l<<" "<<1<<" ";
	    for(int i=l;i<mid;i++) cout<<i<<" ";
	    cout<<endl;
	    int num;cin>>num;
	    if(num==mx) r=mid;
	    else l=mid;
	}
	int u=l;
	cout<<1<<" "<<n-1<<" "<<u<<" ";
	for(int i=1;i<=n;i++){
	    if(i!=u) cout<<i<<" ";
	}
	cout<<endl;
	int ans;cin>>ans;
	cout<<-1<<" "<<ans<<endl;
    }
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.