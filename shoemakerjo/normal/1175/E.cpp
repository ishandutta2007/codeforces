#include <bits/stdc++.h>

using namespace std;
const int maxn = 500010;
int n, m;

int mright[maxn]; //max to the mright
int jump[21][maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		mright[l] = max(mright[l], r);
	}
	for (int i = 1; i < maxn; i++) {
		mright[i] = max(mright[i], mright[i-1]);
	}

	for (int i = 0; i < maxn; i++) {
		if (mright[i] > i) {
			jump[0][i] = mright[i];
		}
		else jump[0][i] = -1;
	}

	for (int i = 1; i < 21; i++) {
		for (int j = 0; j < maxn; j++) {
			if (jump[i-1][j] != -1) {
				jump[i][j] = jump[i-1][jump[i-1][j]];
			}
			else jump[i][j] = -1;
		}
	}

	while (m--) {
		cin >> l >> r;
		int res = 0;
		for (int i = 20; i >= 0; i--) {
			if (jump[i][l] != -1 && jump[i][l] < r) {
				res += (1 << i);
				l = jump[i][l];
			}
		}
		if (jump[0][l] < r) {
			res = -1;
		}
		else res++;
		cout << res  << '\n';
	}
	cout.flush();

}