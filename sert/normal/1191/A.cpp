#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> v = {1, 3, 2, 0};
	for (int i = 0; i < 4; i++) {
		int nid = (v[i] - n % 4 + 4) % 4;
		if (nid < 3) {
			cout << nid << " " << char('A' + i) << "\n";
			return;
		}
	}
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