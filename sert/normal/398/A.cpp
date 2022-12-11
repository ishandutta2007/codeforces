#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)1e18 + 41;
// const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

ll kek(ll x) {
	return x * x;
}

void solve() {
	int x, o;
	cin >> o >> x;
	if (o == 0) {
		cout << -(ll)x * x << "\n" << string(x, 'x') << "\n";
		return;
	}
	if (x == 0) {
		cout << (ll)o * o << "\n" << string(o, 'o') << "\n";
		return;
	}
	if (x == 1) {
		cout << (ll)o * o - 1 << "\n" << string(o, 'o') + 'x' << "\n";
		return;
	}
	ll bst = -INF;
	int bsttot = -1;
	for (int tot = 2; tot <= x; tot++) {
		if (o + 1 < tot) continue;
		int sum0 = x / tot;
		int num1 = x % tot;
		int num0 = tot - num1;
		ll cur = tot - 2 + kek(o - tot + 2) - kek(sum0) * num0 - kek(sum0 + 1) * num1; 
		if (cur > bst) {
			bst = cur;
			bsttot = tot;
		}
	}

	cout << bst << "\n";
	int tot = bsttot;
	int sum0 = x / tot;
	int num1 = x % tot;
	int num0 = tot - num1;
	string s;
	for (int i = 0; i < tot; i++) {
		if (i == 1) s += string(o - tot + 2, 'o');
		if (i > 1) s.push_back('o');
		s += string(i < num0 ? sum0 : sum0 + 1, 'x');
	}
	assert(accumulate(s.begin(), s.end(), 0, [&](int sum, char ch) {return sum + (ch == 'o' ? 1 : 0);}) == o);
	assert(accumulate(s.begin(), s.end(), 0, [&](int sum, char ch) {return sum + (ch == 'x' ? 1 : 0);}) == x);
	assert((int)s.length() == o + x);
	if (!D) cout << s << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}