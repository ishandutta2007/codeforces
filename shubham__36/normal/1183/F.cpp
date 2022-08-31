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
	ll a[n];
	forn(i,n) cin >> a[i];
	sort(a,a+n);
	ll s1=-1,s2=-1,s3=-1;
	rforn(i,n-1){
		if(s1!=-1 && s1%a[i]==0) continue;
		if(s2!=-1 && s2%a[i]==0) continue;
		if(s1==-1) s1=a[i];
		else if(s2==-1) s2=a[i];
		else{
			s3=a[i];
			break;
		}
	}
	ll ans = s1;
	if(s2!=-1) ans += s2;
	if(s3!=-1) ans += s3;
	if(s1%30==0 && 31*(s1/30)>ans){
		ll p1 = s1/2;
		ll p2 = s1/3;
		ll p3 = s1/5;
		bool b1 = 0,b2=0,b3=0;
		forn(i,n){
			if(a[i]==p1) b1=1;
			else if(a[i]==p2) b2 = 1;
			else if(a[i]==p3) b3 = 1;
		}
		if(b1 && b2 && b3) ans = 31*(s1/30);
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