#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

const int N = 1e6 + 5;

int n, m, sum[N], row[N], col[N];
bool vis[N];
char s[N];

int main() {
  int T; read(T);
  while (T--) {
  	read(n); read(m);
  	scanf("%s", s + 1);
  	for (int i = 1; i <= n * m; i++) sum[i] = sum[i - 1] + (s[i] == '1');
  	for (int i = 1; i <= m; i++) row[i] = sum[i] > 0, vis[i - 1] = 0;
  	for (int i = m + 1; i <= n * m; i++) row[i] = row[i - m] + (sum[i] > sum[i - m]);
  	for (int i = 1, cur = 0; i <= n * m; i++) {
  	  if (s[i] == '1' && !vis[i % m]) vis[i % m] = 1, cur++;
  	  col[i] = cur;
	}
	for (int i = 1; i <= n * m; i++) printf("%d ", row[i] + col[i]);
	puts("");
  }
  return 0;
}