#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<int> pos;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) pos.push_back(i);
	}
	cout << pos.size() << "\n";
	pos.push_back(n);
	for (int i = 1; i < (int)pos.size(); i++) {
		cout << pos[i] - pos[i - 1] << " ";
	}
	cout << "\n";
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