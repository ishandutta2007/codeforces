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

const ll mmax = 1e6+5;
ll n,m,a,b;
ll pow_m[mmax],pow_n[mmax],inv[mmax];
vector<ll> npr_n,ncr_m;

ll pow(ll a, ll b){
	if(b==0) return 1;
	ll temp = pow(a,b/2);
	temp *= temp;
	temp %= MOD;
	if(b%2 == 1) temp *= a;
	temp %= MOD;
	return temp;
}

void fill_inv(){
	inv[1]=1;
	forsn(i,2,mmax){
		inv[i]=pow(i,MOD-2);
	}
}

void fill_pow_m()
{
	pow_m[0]=1;
	forsn(i,1,mmax){
		pow_m[i]=pow_m[i-1]*m;
		pow_m[i] %= MOD;
	}
	pow_n[0]=1;
	forsn(i,1,mmax){
		pow_n[i]=pow_n[i-1]*n;
		pow_n[i] %= MOD;
	}
}

// void fill_fact_n(){
// 	fact[0]=1;
// 	forsn(i,1,mmax){
// 		fact[i]=fact[i-1]*i;
// 		fact[i] %= MOD;
// 	}
// }

void fill_npr_n(){
	npr_n[0]=1;
	forsn(i,1,n-1){
		npr_n[i]=npr_n[i-1]*(n-1-i);
		npr_n[i] %= MOD;
	}
}

void fill_ncr_m(){
	ncr_m[0]=1;
	forsn(i,1,m){
		ncr_m[i]=ncr_m[i-1]*(m-i);
		ncr_m[i] %= MOD;
		ncr_m[i]*=inv[i];
		ncr_m[i] %= MOD;
	}
	// cout << 2 << ln;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> a >> b;
    npr_n.resize(n-1);
    ncr_m.resize(m);
    fill_pow_m();
    // cout << 1 << ln;
    // forn(i,10) cout << pow_m[i] << " " << pow_n[i] << ln;
    fill_inv();
    // cout << 2 << ln;
    // forn(i,10) cout << inv[i] << " " << inv[i] << ln;
    fill_npr_n();
    // cout << 3 << ln;
    // forn(i,10) cout << npr_n[i] << ln;
    fill_ncr_m();
    // cout << 4 << ln;
    // forn(i,10) cout << ncr_m[i] << ln;
    ll ans = 0;
    ll i=0;
    while(i<=m-1 && i<= n-2){
    	ll temp = ncr_m[i]*npr_n[i];
    	temp %= MOD;
    	temp *= pow_m[n-2-i];
    	temp %= MOD;
    	if(n-i>=3) temp *= pow_n[n-i-3];
    	else temp *= inv[n];
    	temp %= MOD;
    	temp *= i+2;
    	temp %= MOD;
    	ans += temp;
    	ans %= MOD;
    	i++;
    }
    cout << ans << ln;
    return 0;
}