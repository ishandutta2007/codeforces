#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n;
long long c[N], f[N][2];
string s[N][2];

const long long inf = 1ll << 60;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%I64d", &c[i]);
	for (int i = 1; i <= n; i ++) {
		cin >> s[i][0];
		s[i][1] = s[i][0];
		reverse(s[i][1].begin(), s[i][1].end());
	}
	for (int i = 1; i <= n; i ++) f[i][0] = f[i][1] = inf;
	for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 2; j ++) {
			for (int k = 0; k < 2; k ++) {
				if (s[i-1][k] <= s[i][j]) f[i][j] = min(f[i][j], f[i-1][k] + (j ? c[i] : 0));
			}
        }
	}
	if (f[n][0] == inf && f[n][1] == inf) {
		puts("-1"); return 0;
	}
	printf("%I64d\n", min(f[n][0], f[n][1]));
	return 0;
}