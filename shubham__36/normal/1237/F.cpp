#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
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
#include <fstream>
 
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
ll MOD = 998244353;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll mpow(ll a, ll b){
	if(b >= (MOD-1)) b %= (MOD-1);
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}
 
ll mpow(ll a, ll b, ll p){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2,p);
	t1 *= t1;
	t1 %= p;
	if(b%2) t1 *= a;
	t1 %= p;
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

const int mn = 3605;
ll r[mn],c[mn],dpr[mn][mn],dpc[mn][mn];
ll h,w,n;
ll fact[mn];
ll com[mn][mn];

// ll f(ll n, ll r){
// 	if(n<0 || r>n) return 0;
// 	if(r==0) return 1;
// 	ll ans = fact[n]*mpow(fact[r],MOD-2);
// 	ans %= MOD;
// 	ans*=mpow(fact[n-r],MOD-2);
// 	ans %= MOD;
// 	return ans;
// }

void solve(){
	fact[0]=1;
	forsn(i,1,mn) fact[i] = (i*fact[i-1])%MOD;
	com[0][0]=1;
	forsn(i,1,mn){
		forn(j,i+1){
			com[i][j] = com[i-1][j-1]+com[i-1][j];
			if(com[i][j]>=MOD) com[i][j]-=MOD;
		}
	}
	cin >> h >> w >> n;
	forn(i,2*n){
		ll t1,t2;
		cin >> t1 >> t2;
		t1--,t2--;
		r[t1]=1;
		c[t2]=1;
	}
	forn(i,mn){
		dpr[i][0]=1;
		dpc[i][0]=1;
	}
	forsn(i,h,mn) r[i]=1;
	forsn(i,w,mn) c[i]=1;
	ll er=0,ec=0;
	forn(i,mn){
		if(r[i]==0) er++;
		if(c[i]==0) ec++;
	}
	// forn(i,10) cout << fact[i] << " ";
	// cout << ln;
	// forn(i,10) cout << r[i] << " ";
	// cout << ln;
	// forn(i,10) cout << c[i] << " ";
	// cout << ln;
	// cout << er << " " << ec << ln;
	forsn(i,1,mn-2){
		rforn(j,mn-3){
			dpr[j][i] = dpr[j+1][i];
			if(r[j]==0 && r[j+1]==0) {
			    dpr[j][i] += dpr[j+2][i-1];
			    if(dpr[j][i]>=MOD) dpr[j][i] -= MOD;
			}
			dpc[j][i] = dpc[j+1][i];
			if(c[j]==0 && c[j+1]==0) {
			    dpc[j][i] += dpc[j+2][i-1];
			    if(dpc[j][i]>=MOD) dpc[j][i] -= MOD;
			}
		}
	}
	// forn(i,10) cout << dpr[i][1] << " " << dpc[i][1] << ln;
	ll ans = 0;
	forn(i,mn){
		forn(j,mn){
			if(2*i+j > er || 2*j+i > ec) break;
			// if(i+j > 10) break;
			// cout << i << " " << j << ln;
			ll tr1 = (dpr[0][i]*dpc[0][j])%MOD;
			ll tr2 = (fact[i]*fact[j])%MOD;
			ll tr3 = (com[er-2*i][j]*com[ec-2*j][i])%MOD;
			ll t1 = ((tr1*tr2)%MOD) * tr3;
			// cout << tr1 << " " << tr2 << " " << tr3 << " " << tr4 << ln;
			ans += t1;
			ans %= MOD;
		}
	}
	cout << ans << ln;
}
 
int main()
{
	fast_cin();
    ll t=1;
    // cin>>t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}