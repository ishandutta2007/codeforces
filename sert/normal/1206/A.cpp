#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	cin >> m;
	vector<int> b(m);
	for (auto &x : b) cin >> x;
	cout << *max_element(all(a)) << " " << *max_element(all(b)) << "\n";
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