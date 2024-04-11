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
ll MOD = 998244853;
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
#define INF 1e18
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
 
ll mpow(ll a, ll b, ll p){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
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

void solve(){
	ll n,m;
	cin >> n >> m;
	vp64 s;
	ll st=n+1,en=0;
	forn(i,m){
		p64 temp;
		cin >> temp.fi >> temp.se;
		s.pb(temp);
		st = min(st,temp.fi);
		en = max(en,temp.fi);
	}
	st--;
	en--;
	ll b[n];
	forn(i,n) cin >> b[i];
	forsn(i,st,en+1){
		bool bo = 1;
		p64 h[n];
		forn(i,n) h[i]=mp((ll)-1,(ll)-1);
		ll name = 1;
		for(auto it : s){
			h[it.fi-1]=mp(it.se,name++);
		}
		forsn(j,st,i+1){
			p64 temp = ((j==0) ? mp((ll)0,(ll)0) : mp(h[j-1].fi+b[j],h[j-1].se));
			h[j]=max(h[j],temp);
			if(h[j].fi<0) bo=0;
		}
		rforsn(j,en,i){
			p64 temp = ((j==n-1) ? mp((ll)0,(ll)0) : mp(h[j+1].fi+b[j],h[j+1].se));
			h[j]=max(h[j],temp);
			if(h[j].fi<0) bo=0;
		}
		// if(i==5) forn(i,n){
		// 	cout << h[i].fi << " " << h[i].se << ln;
		// }
		if(!bo) continue;
		cout << i+1 << ln;
		bool vis[m];
		forn(i,m) vis[i]=0;
		rforsn(j,i,st){
			if(vis[h[j].se-1]==0){
				cout << h[j].se << " ";
				vis[h[j].se-1]=1;
			}
		}
		forsn(j,i,en+1){
			if(vis[h[j].se-1]==0){
				cout << h[j].se << " ";
				vis[h[j].se-1]=1;
			}
		}
		forn(j,m){
			if(vis[j]==0){
				cout << j+1 << " ";
				vis[j]=1;
			}
		}
		cout << ln;
		return;
	}
	cout << -1 << ln;
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