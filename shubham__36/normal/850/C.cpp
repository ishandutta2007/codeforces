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

map<ll,ll> dp;

ll calc(ll val){
	if(dp.find(val)!=dp.end()) return dp[val];
	ll ans = 0;
	set<ll> s;
	bool bo = false;
	rforn(i,33){
		if((val & (((ll)1)<<i)) || bo){
			bo = true;
			ll temp = (val>>(i+1)) | (val & ((1<<i) - 1));
			// cout << (val>>(i+1)) << " " << ((i==0) ? 0 : (val & ((1<<i) - 1))) << ln;
			// cout << val << " " << i << " " << temp << ln;
			s.insert(calc(temp));
		}
	}
	// sort(vec.begin(),vec.end());
	// forn(i,(ll)vec.size()){
	// 	cout << vec[i] << " ";
	// }
	// cout << ln;
	for(auto in : s){
		if(in==ans) ans++;
		else break;
	}
	dp[val]=ans;
	// cout << val << " " << ans << ln; 
	return ans;
}

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	map<ll,set<ll> > m;
	set<ll> s;
	dp[0]=0;
	forn(i,n){
		ll t1;
		cin >> t1;
		ll fact = 2;
		while(t1!=0 && fact*fact<=t1){
			ll c = 0;
			while(t1%fact==0){
				c++;
				t1 /= fact;
			} 
			if(c!=0){
				m[fact].insert(c);
				s.insert(fact);
			}
			fact++;
		}
		if(t1!=1){
			m[t1].insert(1);
			s.insert(t1);
		}
	}
	ll ans = 0;
	for(auto it : s){
		ll v=0;
		for(auto j : m[it]){
			v += (1<<(j-1));
		}
		ans ^= calc(v);
		// cout << v << " " << ans << ln;
	}
	if(ans){
		cout << "Mojtaba" << ln;
	}
	else{
		cout << "Arpa" << ln;
	}
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