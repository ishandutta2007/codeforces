// Remember...

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
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;

    while(q--){
	int n,k; cin>>n>>k;
	string s; cin>>s;
	string opt="";
	for(int i=0;i<k-1;i++){
	    opt+="()";
	}
	for(int i=0;(2*i)<(n-2*k+2);i++){
	    opt+="(";
	}
	for(int i=0;(2*i)<(n-2*k+2);i++){
	    opt+=")";
	}
	vector<pii> ans;
	for(int i=0;i<n;i++){
	    int pt=i;
	    while(s[pt]!=opt[i])
		pt++;
	    if(pt!=i){
		swap(s[pt], s[i]);
		ans.PB({i,pt});
	    }
	}
	cout<<sz(ans)<<"\n";
	for(pii p:ans){
	    cout<<p.F+1<<" "<<p.S+1<<"\n";
	}	
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")