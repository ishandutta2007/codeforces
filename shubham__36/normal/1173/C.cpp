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

set<ll> s;
v64 a;
ll n;

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

bool check(ll nom){
	set<ll> temp = s;
	ll arr[3*n+5];
	forn(i,n){
		arr[i]=a[i];
	}
	ll turn = 1;
	while(turn<=nom){
		if(n+turn>nom){
			if((ll)temp.size() && temp.find(n+turn-nom)!=temp.end()){
				arr[n+turn-1]=n+turn-nom;
				temp.erase(n+turn-nom);
				if(arr[turn-1]!=0){
					temp.insert(arr[turn-1]);
				}
			}
			else return false;
		}
		else{
			arr[n+turn-1]=0;
			if(arr[turn-1]!=0){
				temp.insert(arr[turn-1]);
			}
		}
		turn++;
	}
	forn(i,n){
		if(arr[nom+i]!=i+1) return false;
	}
	return true;
}

void solve(){
	cin >> n;
	a.resize(n);
	forn(i,n){
		ll t1;
		cin >> t1;
		if(t1) s.insert(t1);
	}
	forn(i,n) cin >> a[i];
	// if(check(3)) cout << "correct" << ln;
	if(check(n-a[n-1])){
		cout << n-a[n-1] << ln;
		return;
	}
	ll l = n,r=2*n;
	while(l!=r){
		ll mid = (l+r)/2;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	cout << l << ln;
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