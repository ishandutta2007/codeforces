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

int x[maxn],frs[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,z;cin>>n>>z;
    for(int i=0;i<n;i++){
	cin>>x[i];
    }
    sort(x,x+n);
    int pt=0;
    for(int i=0;i<n;i++){
	pt=max(pt,i+1);
	while(pt<n && x[pt]-x[i]<z) pt++;
	frs[i]=pt;
    }
    int l=0,r=(n/2)+1;
    while(r-l>1){
	int mid=(l+r)>>1;
	int pt=mid-1;
	for(int i=0;i<mid;i++){
	    pt=max(pt+1,frs[i]);
	}
	if(pt>=n) r=mid;
	else l=mid;
    }
    return cout<<l<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.