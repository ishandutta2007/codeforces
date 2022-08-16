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
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1000000007;
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


void solve(){
	ll n;
	cin >> n;
	ll a[n];
	forn(i,n){
		ll t1;
		cin >> t1;
		a[i]=abs(t1);
	}
	sort(a,a+n);
	set<p64> s;
	ll ans=0;
	forn(i,n){
		s.insert(mp(a[i],i+1));
		if(i!=0 && a[i]==a[i-1]) ans++;
	}
	forn(i,n){
		if(a[i]==0){
			// ans+=n-1;
			continue;
		}
		set<p64>::iterator it= s.upper_bound(mp(a[i],INF));
		it--;
		ans -= (*it).se-1;
		it= s.upper_bound(mp(2*a[i],INF));
		it--;
		ans += (*it).se-1;
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
    forn(i,t) solve();
    return 0;
}