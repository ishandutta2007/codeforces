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

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	forn(i,n) cin >> a[i];
	ll nx[n],pr[n];
	forn(i,n) nx[i]=i+1;
	forn(i,n) pr[i]=i-1;
	set<p64> s;
	forn(i,n){
		s.insert(mp(a[i],i));
	}
	ll ans = 0;
	ll prev = 0;
	ll fact = n-2;
	for(auto it : s){
		if(fact<=0) break;
		ans += fact*(it.fi-prev);
		// cout << fact*(it.fi-prev) << ln;
		prev = it.fi;
		fact--;
		ll index = it.se;
		if(pr[index]!=-1) nx[pr[index]]=nx[index];
		if(nx[index]!=n) pr[nx[index]]=pr[index];
		if(pr[index]!=-1 && nx[index]!=n){
			ans += (min(a[pr[index]],a[nx[index]])-prev);
		}
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
    forn(i,t) {
    	solve();
    }
    return 0;
}