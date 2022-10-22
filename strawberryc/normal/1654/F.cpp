#include <bits/stdc++.h>

const int N = (1 << 18) + 5;

int n, ans;
char s[N];
std::vector<int> rk[N], tmp[N];

struct elem {
  int ox, xo, nm, sl;
} arr[N];

int main() {
  scanf("%d%s", &n, s); n = 1 << n;
  for (int i = 0; i < n; i++) rk[i].push_back(s[i] - 'a');
  for (int k = 1; k < n; k <<= 1) {
  	for (int i = 0; i < n / k; i++) tmp[i] = rk[i], rk[i].clear();
  	for (int i = 0; i < n / k / 2; i++)
  	  for (int j = 0; j < (k << 1); j++)
  	    rk[i].push_back(0);
  	int tot = 0;
  	for (int i = 0; i < n / k / 2; i++)
  	  for (int j = 0; j < k; j++) {
  	  	arr[tot++] = (elem) {i, j, tmp[i << 1][j], tmp[i << 1 | 1][j]};
  	  	arr[tot++] = (elem) {i, j | k, tmp[i << 1 | 1][j], tmp[i << 1][j]};
	  }
	std::sort(arr, arr + n, [&](elem x, elem y) {
	  return x.nm < y.nm || (x.nm == y.nm && x.sl < y.sl);});
	tot = 0;
	for (int i = 0; i < n; i++) {
	  if (!i || arr[i].nm != arr[i - 1].nm || arr[i].sl != arr[i - 1].sl) tot++;
	  rk[arr[i].ox][arr[i].xo] = tot;
	}
  }
  for (int i = 0; i < n; i++) if (rk[0][i] == 1) ans = i;
  for (int i = 0; i < n; i++) putchar(s[i ^ ans]);
  return puts(""), 0;
}