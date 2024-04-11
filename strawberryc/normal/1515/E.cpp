#include <bits/stdc++.h>

const int N = 444;

int n, RX, f[N][N];

int main() {
  std::cin >> n >> RX;
  f[0][0] = 1;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++) {
      if (j > 1) {
      	f[i + 3][j - 1] = (1ll * (j - 1) * f[i][j] + f[i + 3][j - 1]) % RX;
      	f[i + 2][j - 1] = (2ll * (j - 1) * f[i][j] + f[i + 2][j - 1]) % RX;
	  }
	  f[i + 1][j] = (2ll * j * f[i][j] + f[i + 1][j]) % RX;
	  f[i + 2][j] = (2ll * j * f[i][j] + f[i + 2][j]) % RX;
	  f[i + 1][j + 1] = (1ll * (j + 1) * f[i][j] + f[i + 1][j + 1]) % RX;
	}
  return std::cout << f[n][1] << std::endl, 0;
}