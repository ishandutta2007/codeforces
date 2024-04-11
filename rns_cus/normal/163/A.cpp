#include <bits/stdc++.h>
using namespace std;
#define M 5010

const int mod = 1e9 + 7;

int f[M][M], g[M][M];
char s[M], t[M];

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%s %s", s + 1, t + 1);
	int n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 1; i <= n; i++) {
	  for (int j = 1; j <= m; j++) {
      f[i][j] = f[i][j - 1];
      if (s[i] == t[j]) {
        f[i][j] += f[i - 1][j - 1]; f[i][j]++;
        f[i][j] %= mod;
      }
	  }
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
    ans += f[i][m]; if (ans >= mod) ans -= mod;
	}
	cout << ans << endl;
}