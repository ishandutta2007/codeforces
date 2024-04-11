#include <bits/stdc++.h>

const int N = 2e5 + 5;

int a, b, c, d, n, op[N], orz[N], A[N], B[N];
char s[N];

int main() {
  int T; std::cin >> T;
  while (T--) {
  	scanf("%d%d%d%d", &a, &b, &c, &d);
  	n = a + b + (c + d) * 2;
  	scanf("%s", s + 1);
  	int cnt = 0;
  	for (int i = 1; i <= n; i++) if (s[i] == 'A') cnt++;
  	if (cnt != a + c + d) {puts("NO"); continue;}
  	cnt = 0;
  	for (int i = 1, cur; i <= n; i++) {
  	  cur = i == 1 || s[i] == s[i - 1] ? 1 : cur + 1;
  	  if (i == n || s[i] == s[i + 1]) {
  	  	if (cur & 1) op[++cnt] = 0, orz[cnt] = cur >> 1;
  	  	else if (s[i] == 'B') op[++cnt] = 1, orz[cnt] = cur - 1 >> 1;
  	  	else op[++cnt] = 2, orz[cnt] = cur - 1 >> 1;
	  }
	}
	int mx = 0;
	for (int i = 1; i <= cnt; i++) mx += orz[i];
	if (c + d <= mx) {puts("YES"); continue;}
	int w = c + d - mx, t1 = 0, t2 = 0;
	for (int i = 1; i <= cnt; i++)
	  if (op[i] == 1) A[++t1] = orz[i] + 1;
	  else if (op[i] == 2) B[++t2] = orz[i] + 1;
	std::sort(A + 1, A + t1 + 1); std::sort(B + 1, B + t2 + 1);
	for (int i = 1; i <= t1; i++) if (c >= A[i]) c -= A[i], w--;
	for (int i = 1; i <= t2; i++) if (d >= B[i]) d -= B[i], w--;
	if (w > 0) {puts("NO"); continue;}
	puts("YES");
  }
  return 0;
}