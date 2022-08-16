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

typedef unsigned long long ll;
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
#define INF LLONG_MAX
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

ll modinverse(ll a, ll m){
	ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1){
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }
    if (x < 0) x += m0; 
    return x; 
}

ll range(ll l, ll r){
	return l + rand()%(r-l+1);
}

ll f(ll n){
	ll ans = 0;
	while(n!=0){
		ans++;
		n/=10;
	}
	return ans;
}

void solve(ll in){
	ll n;
	cin >> n;
	ll a[n];
	ll nod[n];
	ll lim = 10;
	ll l[n][lim];
	ll r[n][lim];
	forn(i,n) {
		cin >> a[i];
		nod[i]=f(a[i])-1;
		ll temp = a[i];
		ll fact = 1;
		forn(j,lim){
			temp = (temp/fact)*(fact*(ll)10)+(temp%fact);
			l[i][j] = temp;
			fact *= 100;
		}
		temp = a[i];
		fact = 10;
		forn(j,lim){
			temp = (temp/fact)*(fact*(ll)10)+(temp%fact);
			r[i][j] = temp;
			fact *= 100;
		}
	}
	// forn(i,n){
	// 	cout << a[i] << " " << nod[i] << ln;
	// 	forn(j,lim){
	// 		cout << l[i][j] << " ";
	// 	}
	// 	cout << ln;
	// 	forn(j,lim){
	// 		cout << r[i][j] << " ";
	// 	}
	// 	cout << ln;
	// }
	ll ans = 0;
	ll d[10];
	forn(i,10) d[i]=0;
	forn(i,n){
		d[nod[i]]++;
	}
	forn(i,n){
		forn(j,lim){
			ans += d[j]*(r[i][j]%MOD);
			ans %= MOD;
		}
		// cout << ans << ln;
	}
	forn(i,n){
		forn(j,lim){
			ans += d[j]*(l[i][j]%MOD);
			ans %= MOD;
		}
		// cout << d[1] << " " << (l[i][1]%MOD) << ln;
		// cout << ans << ln;
	}
	cout << ans << ln;
}

int main()
{
	fast_cin();
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve(i);
    }
    return 0;
}