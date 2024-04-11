#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> p(n + 1, vector<int>(n + 1, 0));
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int A = -1, B = -1;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'B') {
				B = j;
				if (A == -1) A = j;
			}
		}
		if (A == -1) {ans++; continue;}		
		if (B - A >= k) continue;
		int miny = max(0, i - k + 1);
		int maxy = i + 1;
		int minx = max(0, B - k + 1);
		int maxx = A + 1;
		p[miny][minx]++;
		p[miny][maxx]--;
		p[maxy][minx]--;
		p[maxy][maxx]++;
	}

	for (int j = 0; j < n; j++) {
		int A = -1, B = -1;
		for (int i = 0; i < n; i++) {
			if (a[i][j] == 'B') {
				B = i;
				if (A == -1) A = i;
			}
		}
		if (A == -1) {ans++; continue;}
		if (B - A >= k) continue;
		int miny = max(0, B - k + 1);
		int maxy = A + 1;
		int minx = max(0, j - k + 1);
		int maxx = j + 1;
		p[miny][minx]++;
		p[miny][maxx]--;
		p[maxy][minx]--;
		p[maxy][maxx]++;
	}

	int kek = 0;

	for (int i = 0; i <= n; i++) {		
		for (int j = 0; j <= n; j++) {
			if (i > 0) p[i][j] += p[i - 1][j];
			if (j > 0) p[i][j] += p[i][j - 1];
			if (i * j > 0) p[i][j] -= p[i - 1][j - 1];
		}
	}

	for (int i = 0; i <= n - k; i++) {
		for (int j = 0; j <= n - k; j++) {
			kek = max(p[i][j], kek);
		}
	}
	cout << ans + kek << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	tst = 6;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}