#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	vector<int> a(4);
	for (auto &x : a) cin >> x;
	sort(all(a));
	cout << (a[0] + a[3] == a[1] + a[2] || a[3] == a[0] + a[1] + a[2] ? "YES" : "NO") << "\n";
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