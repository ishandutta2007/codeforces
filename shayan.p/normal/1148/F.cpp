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

ll A[maxn],B[maxn];
int bt[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    ll sm=0;
    for(int i=0;i<n;i++){
	cin>>A[i]>>B[i];
	sm+=A[i];
	bt[i]=__builtin_ctzll(B[i]);
    }
    if(sm<0){
	for(int i=0;i<n;i++)
	    A[i]*=-1;
    }
    ll ans=0;
    for(int i=61;i>=0;i--){
	ll num=0;
	for(int j=0;j<n;j++){
	    if(bt[j]==i) num+=A[j];
	}
	if(num>0){
	    ans|= 1ll<<i;
	    for(int j=0;j<n;j++){
		if(bit(B[j],i)) A[j]*=-1;
	    }
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.