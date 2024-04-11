#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void k() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int lst = a[n - 1];
	int num = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] <= lst) {
			lst = a[i];
			num++;
		}
	}
	cout << n - num << "\n";
}

void solve() {
	int t;
	cin >> t;
	while (t--) k();
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