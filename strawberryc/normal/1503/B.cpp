#include <bits/stdc++.h>

const int M = 1e4 + 5;

int n, tot1, X1[M], Y1[M], tot2, X2[M], Y2[M];

int main() {
  int n, T, x;
  std::cin >> n; T = n * n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i + j & 1) X1[++tot1] = i, Y1[tot1] = j;
      else X2[++tot2] = i, Y2[tot2] = j;
  while (T--) {
  	scanf("%d", &x);
  	if (tot1 && tot2) {
  	  if (x == 1) printf("%d %d %d\n", 2, X2[tot2], Y2[tot2]), tot2--;
  	  else printf("%d %d %d\n", 1, X1[tot1], Y1[tot1]), tot1--;
	}
	else if (tot1) printf("%d %d %d\n", x == 1 ? 3 : 1, X1[tot1], Y1[tot1]), tot1--;
	else printf("%d %d %d\n", x == 2 ? 3 : 2, X2[tot2], Y2[tot2]), tot2--;
	fflush(stdout);
  }
  return 0;
}