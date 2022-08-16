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
#define INF LLONG_MAX
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

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

ll dp[2*1000+1][2*1000+1];
ll n,m,q;

ll f(ll r, ll c){
	if(r<0 || c<0) return 0;
	ll ans = (r*c-(r%(2*n)*(c%(2*m))))/2;
	// cout << ans << " " << r%(2*n) << " " << c%(2*m) << ln;
	ll c1 = r/(2*n),c2 = c/(2*m);
	if(__builtin_popcountll(c1^c2)%2==0) ans += dp[r%(2*n)][c%(2*m)];
	else ans += (r%(2*n))*(c%(2*m))-dp[r%(2*n)][c%(2*m)];
	return ans;
}

void solve(){
	cin >>n >> m >> q;
	ll a[2*n][2*m];
	forn(i,n){
		forn(j,m) {
			char c;
			cin >> c;
			if(c=='1') a[i][j]=1;
			else a[i][j]=0;
		}
	}
	forn(i,n){
		forn(j,m) {
			a[i+n][j]=1-a[i][j];
			a[i][j+m]=1-a[i][j];
			a[i+n][j+m] = a[i][j];
		}
	}
	ll sumr;
	forn(i,2*n){
		sumr = 0;
		forn(j,2*m){
			if(a[i][j]==1) sumr++;
			dp[i+1][j+1]=dp[i][j+1]+sumr;
		}
	}
	// cout << f(9,4) << ln;
	// cout << f(9,4) << " " << f(9,3) << " " << f(5,3) << " " << f(4,3) << ln;
	forn(i,q){
		ll a1,a2,a3,a4;
		cin >> a1 >> a2 >> a3 >> a4;
		ll ans = f(a3,a4)-f(a3,a2-1)-f(a1-1,a4)+f(a1-1,a2-1);
		cout << ans << ln;
	}
}


int main()
{
	fast_cin();
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}