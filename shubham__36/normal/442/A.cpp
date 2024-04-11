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

ll fun(char c){
	if(c=='B') return 0;
	else if(c=='Y') return 1;
	else if(c=='W') return 2;
	else if(c=='G') return 3;
	else return 4;
}

void solve(){
	ll n;
	cin >> n;
	set<p64> s;
	ll a[5],b[5];
	forn(i,5) a[i]=b[i]=0;
	forn(i,n){
		char c;
		ll t1;
		cin >> c >> t1;
		t1--;
		a[fun(c)]=1;
		b[t1]=1;
		s.insert(mp(fun(c),t1));
	}
	ll c1=0,c2=0;
	forn(i,5){
		if(a[i]) c1++;
		if(b[i]) c2++;
	}
	// cout << c1 << " " << c2 << ln; 
	ll ans=10;
	forn(i,(ll)1<<10){
		bool bo = true;
		set<p64> temp;
		for(auto it : s){
			p64 t1 = mp(-1,-1);
			if(i&(1<<it.fi)) t1.fi = it.fi;
			if(i&(1<<(it.se+5))) t1.se = it.se+5;
			if(temp.find(t1)!=temp.end()){
				bo = false;
				break;
			}
			else{
				temp.insert(t1);
			}
		}
		if(bo){
			// cout << i << ln;
			ll temp = (ll)__builtin_popcount (i);
			// ll a1 = i/(1<<5);
			// ll a2 = i%(1<<5);
			// // cout << a1 << " " << a2 << ln;
			// // cout << (ll)__builtin_popcount(a1) << " " << (ll)__builtin_popcount(a2) << ln; 
			// if((ll)__builtin_popcount(a1)==c2) temp--;
			// if((ll)__builtin_popcount(a2)==c1) temp--;
			ans = min(ans,temp);
		}
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
    forn(i,t) {
    	solve();
    }
    return 0;
}