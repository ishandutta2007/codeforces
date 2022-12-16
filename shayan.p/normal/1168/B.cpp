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

string s;

bool ok(int l,int r){
    for(int i=l;i<=r-2;i++){
	if((i&1)!=(r&1)) continue;
	if(s[i]==s[r] && s[r]==s[(r+i)/2]) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>s;
    int n=sz(s);
    ll ans=1ll*n*(n+1) /2;
    for(int l=0;l<n;l++){
	int r=l;
	while(r<n && ok(l,r)) ans--,r++;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.