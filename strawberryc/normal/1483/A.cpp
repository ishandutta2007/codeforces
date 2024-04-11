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

const int N = 1e5 + 5;

int n, m, k[N], ans[N], cnt[N];
std::vector<int> a[N];

void yhjssa() {
  int x;
  read(n); read(m);
  for (int i = 1; i <= m; i++) {
  	read(k[i]); a[i].clear();
  	for (int j = 1; j <= k[i]; j++)
  	  read(x), a[i].push_back(x);
  }
  for (int i = 1; i <= n; i++) cnt[i] = 0;
  for (int i = 1; i <= m; i++)
    if (k[i] == 1) cnt[a[i][0]]++, ans[i] = a[i][0];
  for (int i = 1; i <= n; i++)
    if (cnt[i] > (m + 1 >> 1)) return (void) puts("NO");
  puts("YES");
  for (int i = 1; i <= m; i++)
    if (k[i] > 1) {
      if (cnt[a[i][0]] < cnt[a[i][1]]) cnt[a[i][0]]++, ans[i] = a[i][0];
      else cnt[a[i][1]]++, ans[i] = a[i][1];
    }
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  puts("");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}