#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
	int x;
	cin >> x;
	cout << r.end() - lower_bound(r.begin(), r.end(), x) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 3;
	for (int i = 1; i < T; i++) solve();	
#endif
}