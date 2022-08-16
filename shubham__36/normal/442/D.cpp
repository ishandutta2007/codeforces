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

vp64 val;
v64 pr;
v64 dp;

void solve(){
	ll n;
	cin >> n;
	val.resize(n+5,mp(0,0));
	pr.resize(n+5,0);
	dp.resize(n+5,0);
	ll ans = 0;
	forn(i,n){
		ll p;
		cin >> p;
		pr[i+2]=p;
		ll cur = i+2;
		dp[cur]=1;
		while(true){
			if(pr[cur]==1){
				ans = max(ans,dp[cur]);
				break;
			}
			if(dp[cur]>val[pr[cur]].fi){
				val[pr[cur]] = mp(dp[cur],val[pr[cur]].fi);
			}
			else if(dp[cur]>val[pr[cur]].se){
				val[pr[cur]] = mp(val[pr[cur]].fi,dp[cur]);
			}
			if(dp[pr[cur]]==max(val[pr[cur]].fi,val[pr[cur]].se+1)){
				break;
			}
			dp[pr[cur]]=max(val[pr[cur]].fi,val[pr[cur]].se+1);
			cur = pr[cur];
		}
		cout << ans << " ";
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