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

const int maxn=110,mod=1e9+7;
const ll inf=1e18;

int a[maxn][maxn];
vector<pii> v;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,m; cin>>n>>m;

    for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
	    cin>>a[i][j];
	}
	for(int j=0;j<n-1;j++){
	    a[i][j]-=a[i][n-1];
	}
    }
    for(int i=0;i<m;i++){
	ans.PB(i);
    }
    for(int i=0;i<n-1;i++){
	v.clear();
	for(int j=0;j<m;j++){
	    v.PB({a[j][i], j});
	}
	sort(v.begin(), v.end(), greater<pii>());

	int sm=0, pt=0;
	while(pt<sz(v) && sm>=0){
	    sm+= v[pt].F;
	    pt++;
	}
	if(sm<0) pt--;
	if(sz(ans) > m-pt){
	    ans.clear();
	    while(pt<sz(v))
		ans.PB(v[pt].S), pt++;
	}
    }
    cout<<sz(ans)<<"\n";
    for(int x:ans){
	cout<<x+1<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")