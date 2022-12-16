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

ll x[maxn],p[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    ll g=0;
    for(int i=0;i<n;i++){
	cin>>x[i];
	g=__gcd(g,x[i]-x[0]);
    }
    int id=-1;
    for(int i=0;i<m;i++){
	cin>>p[i];
	if(g%p[i]==0)
	    id=i;
    }
    if(id==-1) return cout<<"NO\n",0;
    cout<<"YES\n";
    return cout<<x[0]<<" "<<id+1<<"\n",0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.