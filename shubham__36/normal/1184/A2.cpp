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
#define INF LLONG_MAX/2e5

void solve(ll index){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll count = 0;
	forn(i,n){
		if(s[i]=='1') count++;
	}
	if(count%2){
		cout << 0 << ln;
	}
	else if(!count){
		cout << n << ln;
	}
	else{
		ll ans = 0;
		map<ll,ll> m;
		m[1]=0;	
		forsn(i,2,n){
			if(n%i==0){
				ll fact = i;
				bool bo = 0;
				forn(j,fact){
					ll count = 0;
					forn(k,n/fact){
						if(s[k*fact+j]=='1') count++;
					}
					if(count%2){
						bo = 1;
						break;
					}
				}
				m[fact]=bo;
			}
		}
		forsn(i,1,n){
			ll fact = gcd(n,i);
			if(m[fact]==0){
				ans++;
			}
		}
		cout << ans << ln;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve(i+1);
    return 0;
}