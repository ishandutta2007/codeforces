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

void solve(){
	string s1,s2;
	cin >> s1 >> s2;
	ll c1=0,c2=0;
	ll in1=0,in2=0;
	while(in1<(ll)s1.size() && in2<(ll)s2.size()){
		c1=c2=1;
		char c = s1[in1];
		if(s1[in1]!=s2[in2]){
			cout << "NO" << ln;
			return;
		}
		in1++,in2++;
		while(s1[in1]==c){
			c1++;
			in1++;
		}
		while(s2[in2]==c){
			c2++;
			in2++;
		}
		if(c1>c2){
			cout << "NO" << ln;
			return;
		}
	}
	if(in1!=(ll)s1.size() || in2!=(ll)s2.size()){
		cout << "NO" << ln;
		return;
	}
	cout << "YES" << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}