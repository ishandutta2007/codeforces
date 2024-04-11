#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	vector<int> nid(3), a(3);
	for (auto &x : nid) cin >> x;
	for (auto &x : a) cin >> x;
	for (int i = 2; i >= 0; i--) {
		for (int j = i; nid[i] && j >= 0; j--) {
			int x = min(nid[i], a[j]);
			nid[i] -= x;
			a[j] -= x;
		}
		if (nid[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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