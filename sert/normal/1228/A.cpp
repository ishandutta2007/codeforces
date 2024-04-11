#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

bool ok(int x) {
	set<int> s;
	int len = 0;
	while (x > 0) {
		s.insert(x % 10);
		len++;
		x /= 10;
	}
	return ((int)s.size() == len);
}

void solve() {
	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		if (ok(i)) {
			cout << i << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 2;
	for (int i = 1; i < T; i++) solve();	
#endif
}