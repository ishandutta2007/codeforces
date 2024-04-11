#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF LLONG_MAX/2e5

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

ll mlog(ll v){
	ll ans = 20;
	while(v<(((ll)1)<<ans)) ans--;
	return ans;
}

void solve(){
	ll n,m,q;
	cin >> n >> m >> q;
	ll a[n];
	forn(i,n) cin >> a[i];
	ll f[n+1],r[n+1];
	forn(i,n){
		f[a[i]]=a[(i+1)%n];
		r[a[(i+1)%n]]=a[i];
	}
	ll arr[m];
	forn(i,m) cin >> arr[i];
	v64 v[n+1];
	ll logn = 20;
	ll dp[m][logn];
	forn(i,m) dp[i][0]=-1;
	forn(i,m){
		// cout << i << ln;
		v[arr[i]].pb(i);
		// cout << r[arr[i]] << ln;
		if(!(ll)v[r[arr[i]]].size()) continue;
		// cout << i << ln;
		forn(j,(ll)v[r[arr[i]]].size()){
			dp[v[r[arr[i]]][j]][0]=i;
		}
		// cout << i << ln;
		v[r[arr[i]]].clear();
		// cout << i << ln;
	}
	forsn(j,1,logn){
		forn(i,m){
			if(dp[i][j-1]!=-1) dp[i][j]=dp[dp[i][j-1]][j-1];
			else dp[i][j]=-1;
		}
	}
	// forn(j,3){
	// 	forn(i,m){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << ln;
	// }
	ll ans[m];
	forn(i,m){
		ll temp = n-1;
		ll ind = i;
		while(temp>0){
			if(!temp) break;
			ll jump = mlog(temp);
			ind = dp[ind][jump];
			if(ind==-1){
				break;
			}
			temp -= (((ll)1)<<jump);
		}
		if(temp>0){
			ans[i]=m;
		}
		else{
			ans[i]=ind;
		}
	}
	rforn(i,m-2) ans[i]=min(ans[i],ans[i+1]);
	// forn(i,m) cout << ans[i] << " ";
	// cout << ln;
	// cout << ans[44] << ln;
	forn(i,q){
		ll t1,t2;
		cin >> t1 >> t2;
		t1--,t2--;
		if(ans[t1]<=t2) cout << 1;
		else cout << 0;
	}
	cout << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}