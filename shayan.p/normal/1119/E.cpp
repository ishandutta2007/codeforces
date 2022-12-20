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

int a[maxn],pt;
set<int>ids;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    ll ans=0;
    for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]==1) ids.insert(i);
    }
    for(int i=n-1;i>=0;i--){
	while(sz(ids) && *ids.rbegin()>=i) a[*ids.rbegin()]=0,ids.erase(*ids.rbegin());
	if(a[i]==0) continue;
	while(pt<n && a[pt]==0) ++pt;
	if(a[i]&1){
	    a[i]-=3;
	    ans++;
	}
	while(a[i] && sz(ids)){
	    a[*ids.rbegin()]=0;
	    ids.erase(*ids.rbegin());
	    ans++;
	    a[i]-=2;
	}
	while(a[i] && pt<i){
	    int num=min(a[i]/2,a[pt]);
	    a[pt]-=num;
	    ans+=num;
	    a[i]-=2*num;
            if(a[pt]==1) ids.insert(pt);
	    while(pt<n && a[pt]==0) ++pt;
	}
	if(i==pt){
	    ans+=a[i]/3;
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.