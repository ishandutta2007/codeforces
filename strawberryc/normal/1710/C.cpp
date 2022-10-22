#include <bits/stdc++.h>

const int N = 2e5 + 5, wd = 998244353;

int n, nval, ans, f[N][2][2][2][2][2][2];
char s[N];

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i * 2 <= n; i++) std::swap(s[i], s[n - i + 1]);
  f[0][0][0][0][0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int x1 = 0; x1 < 2; x1++) for (int x2 = 0; x2 < 2; x2++)
    for (int x3 = 0; x3 < 2; x3++) for (int u1 = 0; u1 < 2; u1++)
    for (int u2 = 0; u2 < 2; u2++) for (int u3 = 0; u3 < 2; u3++)
    for (int a = 0; a < 2; a++) for (int b = 0; b < 2; b++)
    for (int c = 0; c < 2; c++) {
      int nx1 = a > s[i + 1] - '0' || (a == s[i + 1] - '0' && x1);
      int nx2 = b > s[i + 1] - '0' || (b == s[i + 1] - '0' && x2);
      int nx3 = c > s[i + 1] - '0' || (c == s[i + 1] - '0' && x3);
      int nu1 = u1 || ((a ^ b) && (a ^ c));
      int nu2 = u2 || ((b ^ a) && (b ^ c));
      int nu3 = u3 || ((c ^ a) && (c ^ b));
      f[i + 1][nx1][nx2][nx3][nu1][nu2][nu3]
        = (f[i + 1][nx1][nx2][nx3][nu1][nu2][nu3]
		  + f[i][x1][x2][x3][u1][u2][u3]) % wd;
	}
  return std::cout << f[n][0][0][0][1][1][1] << std::endl, 0;
}