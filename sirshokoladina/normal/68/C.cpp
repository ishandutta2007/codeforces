#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

int l[10][10], h[10][10], c[10][10];
int ans[1000];
int go[10][10];
int n;

int coast(int a, int b) {
	if (!go[a][b]) {
		return 0;
	}
	return c[a][b] + go[a][b] * go[a][b];
}

void rec(int a, int b, int s) {
	if (b == n) {
		a++;
		b = a + 1;
	}
	if (b == n) {
		int p = 0;
		for (int i = 1; i < n; i++) {
			p += go[0][i];
		}
		ans[p] = max(s, ans[p]);
		return;
	}
	if (b == n - 1 && a != 0) {
		int sum = 0;
		forn (i, n - 1) {
			if (i < a) {
				sum += go[i][a];
			}
			if (i > a) {
				sum -= go[a][i];
			}
		}
		if (sum < l[a][b] || sum > h[a][b]) {
			return;
		}
		go[a][b] = sum;
		rec(a, b + 1, s + coast(a, b));
		return;
	}
	for (int i = l[a][b]; i <= h[a][b]; i++) {
		go[a][b] = i;
		rec(a, b + 1, s + coast(a, b));
	}
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	cin >> n;
	forn (i, n * (n - 1) / 2) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		cin >> l[u][v] >> h[u][v] >> c[u][v];
	}
	forn (i, 1000) {
		ans[i] = -1;
	}
	rec(0, 1, 0);
	int k = 0;
	while (k < 1000 && ans[k] < 0) {
		k++;
	}
	if (k == 1000) {
		cout << "-1 -1";
		return 0;
	}
	cout << k << ' ' << ans[k];
}