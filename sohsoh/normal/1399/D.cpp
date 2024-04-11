/*
    Soheil Mohammadkhani
    Test contest on vim :)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], B[MAXN];

char last[MAXN];


ll solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	stack<ll> lo, lz;
	vector<ll> v;
	ll ind = 1;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		if (c == '1') {
			if (lz.empty()) lz.push(ind), ind++;
			v.push_back(lz.top());
			lo.push(lz.top());
			lz.pop();
		} else {
			if (lo.empty()) lo.push(ind), ind++;
                        v.push_back(lo.top());
                        lz.push(lo.top());
                        lo.pop();
		
		}
	}
	cout << *max_element(all(v)) << endl;
	for (ll e : v) cout << e << sep;
	cout << endl;
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();
}

// Save your code before compile and sumbit :)