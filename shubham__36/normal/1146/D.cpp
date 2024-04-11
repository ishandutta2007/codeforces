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

ll n,a,b;
v64 v;

void f(ll x){
	// cout << x << ln;
	if(x-b>=0 && v[x-b]>v[x]){
		v[x-b]=v[x];
		f(x-b);
	}
	if(x+a<=n && v[x+a]>max(x+a,v[x])){
		v[x+a]=max(x+a,v[x]);
		f(x+a);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll m;
	cin >> m >> a >> b;
	n = 500000;
	v.resize(n+1,INF);
	ll cf = __gcd(a,b);
	a/=cf;
	b/=cf;
	v[0]=0;
	f(0);
	ll ans = 0;
	if(m<cf*n){
		for(ll i=0; i<=m ; i+=cf){
			if(m+1 > cf*v[i/cf]) ans += (m+1-cf*v[i/cf]);
		}
	}
	else{
		for(ll i=0; i<=cf*n ; i+=cf){
			if(m+1 > cf*v[i/cf]) ans += (m+1-cf*v[i/cf]);
		}
		ll noterms = (m+1)/cf - n;
		ll sum = 2*(m+1)-2*cf*(n+1);
		sum -= (noterms-1)*cf;
		sum *= noterms;
		sum /= 2;
		ans += sum;
	}
	cout << ans << ln;
    return 0;
}