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

ll f(v64 &v, ll s, ll e){
	if(s>=e) return 0;
	ll mid=(s+e)/2;
	ll ans = f(v,s,mid)+f(v,mid+1,e);
	v64 temp;
	forsn(i,mid+1,e+1){
		temp.pb(v[i]);
	}
	sort(temp.begin(),temp.end());
	forsn(i,s,mid+1){
		ll l=0,r=temp.size();
		while(l!=r){
			ll mid=(l+r)/2;
			if(temp[mid]>v[i]){
				r=mid;
			}
			else{
				l = mid+1;
			}
		}
		ans+=l;
		ans%=MOD;
	}
	// cout << s << " " << e << " " << ans << ln;
	return ans;
}

ll mpow(ll a,ll b){
	if(b==0) return 1;
	ll ans = mpow(a,b/2);
	if(b%2){
		ans *= (ans*a)%MOD;
		ans %= MOD;
	}
	else{
		ans *= ans;
		ans %= MOD;
	}
	return ans;
}

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	set <ll> s;
	ll prev[n];
	ll ind[n];
	forn(i,n) prev[i]=0,ind[i]=-1;
	forn(i,n){
		cin >> a[i];
		if(a[i]!=-1) {
			s.insert(a[i]);
			ind[a[i]-1]=i;
			if(i!=0) prev[i]=prev[i-1];
		}
		else {
			if(i!=0) prev[i]=prev[i-1];
			prev[i]++;
		}
	}
	ll mp[n];
	forn(i,n) mp[i]=-1;
	ll in=0;
	for(auto it : s){
		mp[it-1]=in;
		in++;
	}
	v64 v;
	forn(i,n){
		if(a[i]!=-1){
			v.pb(mp[a[i]-1]);
		}
	}
	// forn(i,n){
	// 	cout << prev[i] << " ";
	// }
	// cout << ln;
	ll ans = f(v,0,(ll)v.size()-1);
	// cout << ans << ln;
	ll tot = prev[n-1];
	// cout << "tot = " << tot << ln;
	if(tot!=0){
		if(tot>1){
		    ll tmp = ((tot)*(tot-1))/2;
			tmp %= MOD;
			if(tmp%2){
				ans+=tmp*mpow(2,MOD-2);
			}
			else{
				ans += tmp/2;
			}
			ans %= MOD;
		}
		ll fact = mpow(tot,MOD-2);
		forn(i,n){
			if(mp[i]!=-1){
				ll prv1 = prev[ind[i]];
				ll sml = i-mp[i];
				ll lrg = tot - sml;
				ll nxt1 = tot - prv1;
				// cout << prv1 << " " << sml << " " << lrg << " " << nxt1 << ln;
				ans += ((prv1*lrg + nxt1*sml)%MOD)*fact;
				ans %= MOD;
			}
		}
	}
	cout << ans%MOD << ln ;
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