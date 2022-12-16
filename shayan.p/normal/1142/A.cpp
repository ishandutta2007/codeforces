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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int n,k;

pll Better(pll a,pll b){
    a.F=min(a.F,b.F);
    a.S=max(a.S,b.S);
    return a;
}
pll f(int l){
    l%=k;
    l=(l+k)%k;
    ll mn=inf,mx=-inf;
    for(int i=0;i<n;i++){
	ll num=1ll*n*k/__gcd(1ll*n*k,1ll*l+1ll*i*k);
	mn=min(mn,num);
	mx=max(mx,num);
    }
    return {mn,mx};
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    int a,b;cin>>a>>b;
    pll ans=Better(Better(f(b-a),f(-b-a)),Better(f(-b+a),f(b+a)));
    cout<<ans.F<<" "<<ans.S<<endl;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.