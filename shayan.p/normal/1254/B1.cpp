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

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    int sm=0;
    
    for(int i=0;i<n;i++){
	cin>>a[i];
	sm+= a[i];
    }
    ll ans=inf;
    for(int i=2;i<=sm;i++){
	if(sm % i == 0){
	    int p=i/2, cnt=0;
	    ll num=0;
	    for(int j=0;j<n;j++){
		if(a[j]==0) continue;
		if(cnt < p){
		    num-=j;
		}
		else{
		    num+=j;
		}
		if(cnt == p){
		    num+= 1ll *p * j;
		    num-= 1ll* (i-p) *j;
		}
		cnt++;
		if(cnt == i){
		    cnt=0;		    
		}
	    }
	    ans= min(ans, num);
	}
    }
    if(ans == inf) ans=-1;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")