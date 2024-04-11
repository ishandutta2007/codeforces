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

    int n,m; cin>>n>>m;
    if(n==1 && m==1){
	return cout<<0<<endl,0;
    }
    if(m!=1){
	for(int i=1; i<=n; i++){
	    for(int j=1; j<=m; j++){
		cout<<i * (n + j)<<" ";
	    }
	    cout<<"\n";
	}
    }
    else{
	for(int i=1; i<=n; i++){
	    for(int j=1; j<=m; j++){
		cout<<(i+m) * j<<" ";
	    }
	    cout<<"\n";
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