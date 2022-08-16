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
	ll n;
	cin >> n;
	ll a[n][5];
	forn(i,n) forn(p,5) cin >> a[i][p];
	ll mark[n];
	forn(i,n) mark[i]=0;
	ll c = 0;
	if(n>100){
		cout << 0 << ln;
	}
	else{
		forn(i,n){
			forn(j,n){
				forn(k,n){
					if(i==j || j==k || i==k) continue;
					ll val=0;
					forn(p,5){
						val += (a[i][p]-a[j][p])*(a[i][p]-a[k][p]);
					}
					if(val>0 && mark[i]==0){
						mark[i]=1;
						c++;
					}
				}
			}
		}
		cout << n-c << ln;
		forn(i,n){
			if(mark[i]==0) cout << i+1 << " ";
		}
		cout << ln;
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