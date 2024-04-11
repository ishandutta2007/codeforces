#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int N = 200200;
const int L = 25;
int prec[N][L];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 0; i + 1 < N; ++i) {
		for (int j = 0; j + 1 < L; ++j) {
			prec[i + 1][j] = prec[i][j] + (i >> j & 1);
		}
	}
	while (t--) {
		int l, r;
		cin >> l >> r;
		int mn = 1e9;
		for(int i = 0; i < 25; ++i) {
			int cnt = prec[r + 1][i] - prec[l][i];
			cnt = r - l + 1 - cnt;
			mn = min(mn, cnt);
		}
		cout << mn << '\n';
	}
}