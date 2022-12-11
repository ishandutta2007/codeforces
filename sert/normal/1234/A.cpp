#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void kek() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	cout << (accumulate(all(a), 0) + n - 1) / n << "\n";
}

void solve() {
	int t;
	cin >> t;
	while (t--) {
		kek();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 1;
	for (int i = 1; i < T; i++) solve();	
#endif
}