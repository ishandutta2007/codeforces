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
	ll n;
	cin >> n;
	bitset<64> a[n];
	ll s = 0;
	forn(i,n) forn(j,64) a[i][j]=0;
	forn(i,n){
		ll t1,t2;
		cin >> t1 >> t2;
		s ^= t1;
		t2 ^= t1;
		forn(j,64){
			if(!t2) break;
			if(t2%2){
				a[i][j]=1;
			}
			t2/=2;
		}
	}
	ll in=0;
	forn(i,64){
		bool bo = 0;
		forsn(j,in,n){
			if(a[j][i]==1){
				bo = 1;
				if(j!=in) swap(a[j],a[in]);
				break;
			}
		}
		// cout << s << " " << in << ln;
		if(!bo & s%2){
			cout << "1/1" << ln;
			return;
		}
		else if(bo){
			if(s%2)
			forsn(k,i,64){
				if(a[in][k]==1) {
					s ^= (((ll)1)<<(k-i));
					// cout << s << ln;
				}
			}
			forsn(j,in+1,n){
				if(a[j][i]==1){
					a[j]^=a[in];
				}
			}
			in++;
		}
		s/=2;
		// cout << s << " " << in << ln;
	}
	ll temp = (ll)1<<in;
	cout << (temp - 1) << "/" << temp << ln;
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