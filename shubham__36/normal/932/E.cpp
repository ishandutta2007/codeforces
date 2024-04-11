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
	if(b%2){
		t1 *= a;
		t1 %= MOD;
	}
	return t1;
}

void solve(){
	ll n,k;
	cin >> n >> k;
	ll ans = 0;
	ll p[k+1];
	p[0]=0;
	forsn(i,1,k+1){
		p[i]=mpow(i,k);
	}
	vv64 ncr(k+1);
	forn(i,k+1){
		ncr[i].resize(i+1);
	}
	ncr[0][0]=1;
	forn(i,k+1){
		rforn(j,i){
			if(i==0 || j==0){
				ncr[i][j]=1;
				continue;
			}
			ncr[i][j]=((i-1>=j) ? ncr[i-1][j] : 0) + ((i!=0) ? ncr[i-1][j-1] : 0);
			ncr[i][j]%=MOD;
		}
	}
	ll nc[k+1];
	nc[0]=1;
	forsn(i,1,k+1){
		nc[i]=(nc[i-1]*(n-i+1) % MOD)*mpow(i,MOD-2);
		nc[i]%=MOD;
	}
	// forn(i,k+1){
	// 	cout << p[i] << " ";
	// }
	// cout << ln;
	// forn(i,k+1){
	// 	cout << nc[i] << " ";
	// }
	// cout << ln;
	// forn(i,k+1){
	// 	forn(j,i+1){
	// 		cout << ncr[i][j]  << " ";
	// 	}
	// 	cout << ln;
	// }
	forsn(i,1,k+1){
		ll temp = mpow(2,n-i)*nc[i];
		temp %= MOD;
		ll t1 =0;
		ll sn = 1;
		rforsn(j,i,1){
			t1 += sn*(ncr[i][j]*p[j]%MOD);
			t1 %= MOD;
			t1 += MOD;
			t1 %= MOD;
			sn *= -1;
		}
		temp *= t1;
		temp %= MOD;
		ans += temp;
		ans %= MOD;
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