#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

const int maxn = 600;

bool f[maxn][maxn];

int n, k, c;

vector <int> ans;

int main() {
	n = read(), k = read();
	f[0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		c = read();
		for (int j = k; j >= c; j --) {
			for (int p = 0; p + c <= k; p ++) {
				if (f[j - c][p]) f[j][p] = f[j][p + c] = 1;
			}
		}
	}
	for (int i = 0; i <= k; i ++) if (f[k][i]) ans.push_back(i);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i ++) {
		printf("%d ", ans[i]);
	}
	return 0;
}