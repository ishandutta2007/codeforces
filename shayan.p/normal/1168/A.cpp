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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn],n,m;

bool ok(int mid){
    int MX=m;
    for(int i=n-1;i>=0;i--){
	if(a[i]<=MX){
	    MX= min(MX, a[i]+mid);
	}
	else{
	    if(m-a[i]>mid) return 0;
	    MX=min(MX,mid-(m-a[i]));
	}
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    int l=-1,r=m;
    while(r-l>1){
	int mid=(l+r)>>1;
	if(ok(mid)) r=mid;
	else l=mid;
    }
    return cout<<r<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.