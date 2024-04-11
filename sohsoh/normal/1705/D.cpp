#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

inline string f(string s) {
	string ans = "";
	for (int i = 1; i < int(s.size()); i++)
		ans.push_back((s[i] == s[i - 1] ? '0' : '1'));
	return ans;
}

inline int solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	if (s.front() != t.front()) return cout << -1 << endl, 0;

	s = f(s);
	t = f(t);

	ll ans = 0, x = 0;
	for (int i = 0; i < int(s.size()); i++) {
		x += int(s[i] - '0');
		x -= int(t[i] - '0');
		ans += (x < 0 ? -x : x);
	}

	cout << (x ? -1 : ans) << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}