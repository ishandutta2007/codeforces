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
#define INF LLONG_MAX

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

void solve(){
	ll n;
	cin >> n;
	v64 v;
	v.pb(1);
	ll cur = 1;
	ll ans = 0;
	ll co = 0;
	bool bo = false;
	ll lim = (ll)1 << 32;
	forn(i,n){
		string s;
		cin >> s;
		if(s=="for"){
			ll t1;
			cin >> t1;
			v.pb(t1);
			if(co){
				co++;
			}
			else if(cur * t1 < lim){
				cur *= t1;
			}
			else{
				co = 1;
			}
		}
		else if(s=="end"){
			ll t1 = v[(ll)v.size()-1];
			v.pop_back();
			if(co){
				co--;
			}
			else{
				cur /= t1;
			} 
		}
		else{
			if(co){
				bo = true;
			}
			else if(ans + cur < lim){
				ans += cur;
			}
			else{
				bo = true;
			}
		}
	}
	if(bo) cout << "OVERFLOW!!!" << ln;
	else cout << ans << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve();
    return 0;
}