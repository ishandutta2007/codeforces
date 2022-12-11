#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int x = *max_element(all(a));
	sort(all(a));
	int y = -1;
	for (int i = 0; i < n; i++) {
		if ((i > 0 && a[i] == a[i - 1]) || x % a[i]) y = a[i];
	}
	cout << x << " " << y << "\n";
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