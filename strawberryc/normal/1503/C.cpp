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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 1e5 + 5;

int n;
ll ans;

struct elem {
  int x, y;
} a[N];

inline bool comp(elem a, elem b) {
  return a.x < b.x;
}

int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i].x), read(a[i].y), ans += a[i].y;
  std::sort(a + 1, a + n + 1, comp);
  for (int i = 1, mx = -2147483647; i < n; i++)
    mx = Max(mx, a[i].x + a[i].y), ans += Max(0, a[i + 1].x - mx);
  return std::cout << ans << std::endl, 0;
}