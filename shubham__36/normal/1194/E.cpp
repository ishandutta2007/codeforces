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

void solve(ll index){
	ll n;
	cin >> n;
	vv64 vech;
	vv64 vecv;
	forn(i,n){
		v64 t(4);
		forn(j,4){
			cin >> t[j];
		}
		if(t[0]==t[2]){
			if(t[1]>t[3]) swap(t[1],t[3]);
			vecv.pb(t);
		}
		else{
			if(t[0]>t[2]) swap(t[0],t[2]);
			vech.pb(t);
		}
	}
	const ll szh = (ll)vech.size();
	const ll szv = (ll)vecv.size();
	bitset<5000> cross[szh];
	forn(i,szh){
		forn(j,szv){
			if(vech[i][0]<=vecv[j][0] && vech[i][1]>=vecv[j][1] && vech[i][2]>=vecv[j][2] && vech[i][3]<=vecv[j][3]){
				cross[i][j]=1;
			}
			else cross[i][j]=0;
		}
	}
	if(szh<szv){
		ll ans = 0;
		forn(i,szh){
			forsn(j,i+1,szh){
				ll count = (cross[i]&cross[j]).count();
				ans += ((count)*(count-1))/2;
			}
		}
		cout << ans << ln;
	}
	else{
		bitset<5000> cross1[szv];
		forn(i,szh){
			forn(j,szv){
				cross1[j][i]=cross[i][j];
			}
		}
		ll ans = 0;
		forn(i,szv){
			forsn(j,i+1,szv){
				ll count = (cross1[i]&cross1[j]).count();
				ans += ((count)*(count-1))/2;
			}
		}
		cout << ans << ln;
	}
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