#include <bits/stdc++.h>
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
ll MOD = 998244353;
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

void solve(ll index){
	ll n,k;
	cin >> n >> k;
	ll lim=0;
	ll a[n];
	forn(i,n) {
		cin >> a[i];
		lim = max(lim,a[i]);
	}
	sort(a,a+n);
	ll ans = 0;
	forsn(val,1,lim/(k-1)+1){
		ll dp[n][2];
		forn(i,n) forn(j,2) dp[i][j]=1;
		forn(i,k-1){
			ll in1 = 0;
			ll sum1 = 0;
			forn(j,n){
				ll cur = a[j];
				while(a[in1]+val<=cur && in1<j){
					sum1 += dp[in1][0];
					sum1 %= MOD;
					in1++;
				}
				dp[j][1]=sum1;
			}
			forn(k1,n) dp[k1][0]=dp[k1][1];
			// forn(k1,n) cout << dp[k1][0] << " ";
			// cout << ln;
		}
		forn(i,n){
			ans += dp[i][0];
			ans %= MOD;
		}
		// cout << ans << ln;
	}
	cout << ans << ln;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve(i+1);
    return 0;
}