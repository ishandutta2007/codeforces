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
ll MOD = 1000000007;
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


void solve(){
	ll n;
	cin >> n;
	ll l1=-1,l2=-1;
	forsn(i,5,n+1){
		if(i*i>n) break;
		if(n%i == 0){
			l1 = i;
			l2 = n/i;
			break;
		}
	}
	if(l1 == -1){
		cout << -1 << ln;
	}
	else{
		forn(i,l1){
			forn(j,l2){
				ll in = (i+j)%5;
				// cout << in;
				if(in == 0) cout << "a";
				else if(in == 1) cout << "e";
				else if(in == 2) cout << "i";
				else if(in == 3) cout << "o";
				else cout << "u";
			}
		}
		cout << ln;
	}
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