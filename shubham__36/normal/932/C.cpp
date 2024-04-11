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

void solve(){
	ll n,a,b;
	cin >> n >> a >> b;
	ll a1=-1,a2=-1;
	forn(i,n+1){
		ll sum = n-i*a;
		if(sum<0) break;
		if(sum%b==0){
			a1 = i;
			a2 = sum/b;
			break;
		}
	}
	if(a1==-1){
		cout << -1 << ln;
	}
	else{
		// cout << "entered" << ln;
		ll in = 0;
		forn(i,a1){
			cout << in+a << " ";
			forn(i,a-1){
				cout << in+i+1 << " ";
			}
			in+=a;
		}
		forn(i,a2){
			cout << in+b << " ";
			forn(i,b-1){
				cout << in+i+1 << " ";
			}
			in+=b;
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