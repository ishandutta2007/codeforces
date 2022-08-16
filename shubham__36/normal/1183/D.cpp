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
ll MOD = 1e13+7;
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

void solve(){
	ll n;
	cin >> n;
	p64 count[n];
	forn(i,n) count[i]=mp(0,0);
	forn(i,n){
		ll t1;
		cin >> t1;
		t1--;
		count[t1]=mp(count[t1].fi+1,count[t1].se);
		// else count[t1]=mp(count[t1].fi+1,count[t1].se+1);
	}
	sort(count,count+n);
	multiset<ll> s;
	ll prev = count[n-1].fi;
	ll in = n-1;
	ll ans = 0,sec=0;
	rforsn(i,prev,1){
		while(in>=0 && i==count[in].fi){
			s.insert(-count[in].se);
			in--;
		}
		if((ll)s.size()){
			ans += i;
			// sec += min(i,-(*(s.begin())));
			s.erase(s.begin());
		}
	}
	cout << ans << ln;
}


int main()
{
	fast_cin();
    ll t=1;
    cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}