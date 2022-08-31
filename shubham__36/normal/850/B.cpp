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
	ll n,x,y;
	cin >> n >> x >> y;
	ll f = (x/y);
	ll a[n];
	ll m = 0;
	forn(i,n){
		cin >> a[i];
		m = max(m,a[i]);
	}
	sort(a,a+n);
	ll c[3*m+1],s[3*m+1];
	ll in =0;
	ll val = 0;
	ll sval = 0; 
	forn(i,3*m+1){
		if(in<n && a[in]==i){
			val++;
			sval += i;
			in++;
			i--;
		}
		else{
			c[i]=val;
			s[i]=sval;
		}
	}
	ll ans = n*x;
	forn(i,2*m+1){
		if(i>1){
			ll temp=0;
			for(ll j = i; j<=m+i; j+=i){
				if(f<i){
					temp += ((c[j]-c[j-f-1])*j - (s[j]-s[j-f-1]))*y;
				}
				else{
					temp += ((c[j]-c[j-i])*j - (s[j]-s[j-i]))*y;
				}
				if(f<i){
					temp += (c[j-f-1]-c[j-i])*x;
				}
				// cout << j << " " << temp << ln;
			}
			// cout << i << " " << temp << ln;
			ans = min(ans,temp);
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
    forn(i,t) solve();
    return 0;
}