/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
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

bool B[MAXN] = {false};

ll solve() {
	string s;
	ll x;
	cin >> s >> x;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			if (i + x <= s.size()) B[i + x] = true;
			if (i - x >= 0) B[i - x] = true;
		}
		
	}

	string ans = "";
	for (int i = 0; i < s.size(); i++) {
		if (B[i]) ans.push_back('0');
		else ans.push_back('1');
	}

	
	for (int i = 0; i < s.size() + 100; i++) B[i] = false;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			bool b = true;
			if (i + x < s.size() && ans[i + x] == '1') b = false;
			if (i - x >= 0 && ans[i - x] == '1') b = false;
		      	if (b) return cout << -1 << endl, 0;	
		}
	}

	cout << ans << endl;
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();
}