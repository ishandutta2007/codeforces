#include <bits/stdc++.h>

const int N = 2e5 + 5;

int n, sum[N];
char s[N];

int main() {
  int T; std::cin >> T;
  while (T--) {
  	scanf("%d%s", &n, s + 1);
  	for (int i = 1; i <= n * 2; i++)
	  sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
	bool is = 1;
	for (int i = 1; i <= n * 2; i++)
	  if (sum[i] < 0) is = 0;
	if (is) {puts("0"); continue;}
	int li, ri, pos = 0, mx = -1, mpl, mpr;
	for (int i = 1; i <= n * 2; i++) if (sum[i] < 0) ri = i;
	for (int i = n * 2; i >= 1; i--) if (sum[i] < 0) li = i;
	for (int i = 1; i <= n * 2; i++) if (sum[i] > sum[pos]) pos = i;
	for (int i = li; i <= ri; i++) if (sum[i] > mx) mx = sum[i];
	mpl = li - 1; mpr = ri + 1;
	for (int i = 0; i < li; i++) if (sum[i] > sum[mpl]) mpl = i;
	for (int i = n * 2; i > ri; i--) if (sum[i] > sum[mpr]) mpr = i;
	if (sum[mpl] + sum[mpr] >= mx) {
	  puts("1");
	  printf("%d %d\n", mpl + 1, mpr); continue;
	}
	puts("2");
	printf("%d %d\n%d %d\n", 1, pos, pos + 1, n * 2);
  }
}