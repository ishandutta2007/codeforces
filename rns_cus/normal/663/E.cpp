#include <bits/stdc++.h>
using namespace std;
#define M 21

int f[M][1 << M], n, m, L, a[1 << M], b[1 << M];
char s[M];

int main() {
	//freopen("E.in", "r", stdin);
	cin >> n >> m; L = 1 << n;
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < m; j++) a[j] += (s[j] - '0') << i;
	}
	for (int i = 0; i < m; i++) f[0][a[i]]++;
	for (int i = 0; i < n; i++) {
		for (int k = n; k; k--) {
			for (int j = 0; j < L; j++) f[k][j] += f[k - 1][j ^ (1 << i)];
		}
	}
	for (int j = 0; j <= n; j++) for (int i = 0; i < L; i++) b[i] += min(j, n - j) * f[j][i];
	int ans = n * m;
	for (int i = 0; i < L; i++) if (ans > b[i]) ans = b[i];
	cout << ans << endl;
}