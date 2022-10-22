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

const int N = 2e5 + 5;

int n, m, a[N], b[N];
bool sorted[N];
std::vector<int> A[N];

int main() {
  int T; read(T);
  while (T--) {
  	bool ans = 1;
  	read(n); read(m);
  	int prx = -1, pry = -1;
  	for (int i = 1; i <= n; i++) {
  	  int cnt = 0, ix = -1, iy = -1; A[i].clear();
  	  for (int j = 1; j <= m; j++) read(a[j]), b[j] = a[j],
		A[i].push_back(a[j]);
  	  std::sort(b + 1, b + m + 1);
  	  for (int j = 1; j <= m; j++) if (a[j] != b[j]) {
  	  	cnt++;
  	  	if (cnt == 1) ix = j;
  	  	else if (cnt == 2) iy = j;
	  }
	  if (cnt > 2) ans = 0;
	  sorted[i] = !cnt;
	  if (cnt == 2) {
	  	if (prx == -1 && pry == -1) prx = ix, pry = iy;
	  	if (prx != ix || pry != iy) ans = 0;
	  }
	}
	if (!ans) {puts("-1"); continue;}
	if (prx == -1 && pry == -1) {puts("1 1"); continue;}
	else for (int i = 1; i <= n; i++) if (sorted[i] && A[i][prx - 1] != A[i][pry - 1])
	  ans = 0;
	if (!ans) {puts("-1"); continue;}
	printf("%d %d\n", prx, pry);
  }
  return 0;
}