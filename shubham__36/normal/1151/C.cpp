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
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef unordered_map<int,int> m32;
typedef map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
typedef pair<ll,p64 > pp64;
ll MOD = 1e9 + 7;
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

ll fen(ll in){
	ll va = 2;
	ll s = 1;
	while(4*va<=in){
		s += va;
		va *= 4;
	}
	s += min(va,in-va);
	return s;
}

ll fea(ll in){
	ll va = 2;
	ll s = 1;
	while(4*va<=in){
		s += va;
		va *= 4;
	}
	s += min(va-1,in-va);
	return s;
}

ll gen(ll in){
	ll va = 1;
	ll s = 1;
	while(4*va<=in){
		s += va;
		va *= 4;
	}
	s += min(va,in-va);
	return s;
}

ll gea(ll in){
	ll va = 1;
	ll s = 1;
	while(4*va<=in){
		s += va;
		va *= 4;
	}
	s += min(va-1,in-va);
	return s;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll l,r;
    cin >> l >>r;
    ll a1=fen(l),a2=fea(r);
    ll ans = 0;
    if(a1<=a2){
    	a1 %= MOD;
    	a2 %= MOD;
    	ans += ((a2*(a2+1))%MOD + MOD) - (a1*(a1-1))%MOD; 
    	ans %= MOD;
    } 
    a1=gen(l),a2=gea(r);
    if(a1<=a2){
    	a1 %= MOD;
    	a2 %= MOD;
    	ans += ((a2*a2)%MOD + MOD) - ((a1-1)*(a1-1))%MOD;
    	ans %= MOD; 
    } 
    if(ans < 0) ans+=MOD;
    cout << ans << ln;
    return 0;
}