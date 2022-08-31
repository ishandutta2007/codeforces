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
	ll n,m;
	cin >> n >> m;
	ll r=0,c=0;
	set<ll> a1,b;
	char a[n][m];
	forn(i,n){
		forn(j,m){
			cin >> a[i][j];
		}
	}
	forn(i,n){
		ll t1 = 0;
		set<ll> temp;
		forn(j,m){
			if(a[i][j]=='*') t1++;
			else temp.insert(j);
		}
		if(t1>c){
			c = t1;
			b = temp;
		}
		else if(t1==c){
			for(auto it : temp){
				b.insert(it);
			}
		}
	}
	forn(i,m){
		ll t1 = 0;
		forn(j,n){
			if(a[j][i]=='*') t1++;
		}
		if(t1>r){
			r = t1;
			a1.clear();
			a1.insert(i);
		}
		else if(t1==r){
			a1.insert(i);
		}
	}
	ll ans = n+m-r-c;
	ll t = 0;
	if(ans!=0){
		v64 vis(m,0);
		for(auto it : a1){
			vis[it]++;
		}
		for(auto it : b){
			if(vis[it]) t=1;
		}
	}
	cout << ans-t << ln;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin >> t;
    forn(i,t) solve(i+1);
    return 0;
}