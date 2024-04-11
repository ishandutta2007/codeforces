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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s, t;
	cin >> s >> t;
	
	ll p = 58073, pp = 58073;
	vector<ll> suff, pref;
	ll hsh = 0;
	for (int i = 0; i < t.size(); i++) {
		hsh += (t[i] - '0' + 5) * pp % MOD;
		hsh %= MOD;
	       	pp *= p;
		pp %= MOD;	
		pref.push_back(hsh);
	}

	hsh = 0;
	for (int i = t.size() - 1; i >= 0; i--) {
		hsh = (p * hsh + (t[i] - '0' + 5) * p) % MOD;
		suff.push_back(hsh);
	}

	ll cps = 0;
	for (int i = 0; i < suff.size() - 1; i++)
		if (suff[i] == pref[i]) cps = i + 1;

	debug(cps)

	ll O = count(all(s), '1'), Z = count(all(s), '0');

	string ans = "";
	for (int i = 0; i < t.size(); i++) {
		char c = t[i];
		if (c == '1') {
			if (O <= 0) break;
			O--;
			ans.push_back('1');
		} else {
			if (Z <= 0) break;
			Z--;
			ans.push_back('0');
		}
	}

	for (int i = cps; i < t.size(); i++) {
		char c = t[i];
		if (c == '1') {
			if (O <= 0) break;
			O--;
			ans.push_back('1');
		} else {
			if (Z <= 0) break;
			Z--;
			ans.push_back('0');
		}

		if (i == t.size() - 1) i = cps - 1;
	}

	while (Z--) ans.push_back('0');
	while (O--) ans.push_back('1');
	cout << ans << endl;
	return 0;
}