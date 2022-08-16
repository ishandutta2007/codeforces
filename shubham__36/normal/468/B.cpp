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
	ll n,a,b;
	cin >> n >> a >> b;
	ll arr[n];
	set<ll> s;
	forn(i,n) {
		cin >> arr[i];
		s.insert(arr[i]);
	}
	map<ll,ll> m;
	for(auto i : s){
		if(m.find(i)==m.end()){
			if((m.find(a-i)==m.end() && s.find(a-i)!=s.end()) && (m.find(b-i)==m.end() && s.find(b-i)!=s.end())){
				continue;
			} 
			else if(m.find(a-i)==m.end() && s.find(a-i)!=s.end()){
				ll temp=i;
				while(s.find(temp)!=s.end() && m.find(temp)==m.end() && m.find(a-temp)==m.end() && s.find(a-temp)!=s.end()){
					m[temp]=0;
					m[a-temp]=0;
					temp = b-a+temp;
				}
			}
			else if(m.find(b-i)==m.end() && s.find(b-i)!=s.end()){
				ll temp=i;
				while(s.find(temp)!=s.end() && m.find(temp)==m.end() && m.find(b-temp)==m.end() && s.find(b-temp)!=s.end()){
					m[temp]=1;
					m[b-temp]=1;
					temp = a-b+temp;
				}
			}
		}
	}
	for(auto i : s){
		if(m.find(i)==m.end()){
			if(m.find(a-i)==m.end() && s.find(a-i)!=s.end()){
				m[i]=0;
				m[a-i]=0;
			}
		}
	}
	ll ans[n];
	forn(i,n){
		if(m.find(arr[i])!=m.end()){
			ans[i]=m[arr[i]];
		}
		else{
			cout << "NO" << ln;
			return;
		}
	}
	cout << "YES" << ln;
	forn(i,n) cout << ans[i] << " ";
	cout << ln;
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