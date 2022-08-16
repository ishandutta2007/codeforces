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
typedef unordered_map<ll,ll> m64;
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
ll d;

ll bsearch(ll h, ll l, ll r){
	if(r==0) return h;
	ll k = l+(r/2)*d;
	cout << "> " << k << endl;
	// fflush(stdout);
	ll t;
	cin >> t;
	if(t==0) return bsearch(k,l,r/2);
	else return bsearch(h,k+d,(h-k-d)/d);
}

// ll mgcd(ll a, ll b){
// 	if(b==0) return a;
// 	else return mgcd(b,a-(a/b)*b);
// }

int main(){
	// ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    ll n;
    cin >> n;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> permutation(n);
    for (int i = 0; i < n; i++)
        permutation[i] = i;
    shuffle(permutation.begin(), permutation.end(), rng);
    ll kt = 40;
    ll a[kt];
    forn(i,kt){
    	ll pos = permutation[i%n]+1;
    	cout << "? " << pos << endl;
    	// fflush(stdout);
    	cin >> a[i];
    }
    sort(a,a+kt);
    d = a[1]-a[0];
    forn(i,kt-2){
    	if(a[i+2]-a[i+1]!=0) d = __gcd(d,a[i+2]-a[i+1]);
    }
    ll low = a[kt-1];
    ll hig = a[0]+(n-1)*d;
    ll f = a[0];
    if(d!=0){
    	ll thu = (ll)1e9;
    	if(hig>thu) hig = thu-((thu - low)%d);
    	ll range = (hig-low)/d;
    	f = bsearch(hig,low,range);
    }
    ll x1 = f-(n-1)*d;
    cout << "! " << x1 << " " << d << endl;
    // fflush(stdout);
    return 0;
}