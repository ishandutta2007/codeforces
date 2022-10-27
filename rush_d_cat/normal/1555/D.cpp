#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200000 + 100;
int f[N][3];
int que(int l, int r, int id) {
	int rr = l + ((r+1-l+2)/3) * 3;
	return f[l][id] - f[rr][id];
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	for (int i = n - 1; i >= 0; i --) {
		for (int j = 0; j < 3; j ++) {
			f[i][j] = f[i+3][j];
		}
		f[i][s[i] - 'a'] ++;
	}

	while (m --) {
		int l, r;
		cin >> l >> r;
		l --, r --;

		if (l == r) {
			cout << 0 << "\n";
		} else if (l + 1 == r) {
			cout << (s[l] == s[r] ? 1 : 0) << endl;
		} else {
			int ans = 1e9;
			for (int i = 0; i < 3; i ++) {
				for (int j = 0; j < 3; j ++) {
					for (int k = 0; k < 3; k ++) {
						if (i != j && j != k && i != k)
							ans = min(ans, (r-l+1) - (que(l, r, i) + que(l+1, r, j) + que(l+2, r, k)));
					}
				}
			}
			cout << ans << "\n";
		}

	}
}