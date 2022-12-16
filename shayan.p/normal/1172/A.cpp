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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

int ans,a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    int pss=-1;
    for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]==1) pss=i;
	if(a[i]!=0) ans=max(ans,i+n-(a[i]-1)+1);
    }
    while(ans<n && a[ans]==0){
	ans++;
    }
    if(pss!=-1){
	bool is=0;
	for(int i=pss;i<n;i++){
	    is|= a[i]!=i-pss+1;
	}
	if(!is){
	    is=0;
	    for(int i=0;i<pss;i++){
		is|= a[i]!=0 && pss+a[i]-1-i<=n;
	    }
	    if(!is) ans=pss;
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.