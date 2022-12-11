#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) 
		cin >> x;
	for (int i = 0; i < n; i++) a.push_back(a[i]);
	int ans = 0;
	int cur = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] == 1) cur++;
		else {
			ans = max(ans, cur);
			cur = 0;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 4;
	for (int i = 1; i < T; i++) solve();	
#endif
}