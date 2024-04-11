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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 2e5 + 5;

int n, ans, mx[N], mn[N], tot, l[N], r[N];
bool is1[N], is2[N];

struct elem {
  int x, y; bool typ;
} a[N];

inline bool comp(elem a, elem b) {return a.y < b.y;}

int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
  	read(a[i].x); read(a[i].y);
  	if (a[i].x > a[i].y) std::swap(a[i].x, a[i].y), a[i].typ = 1;
  }
  std::sort(a + 1, a + n + 1, comp);
  mn[0] = 999999; mx[n + 1] = -999999;
  for (int i = 1; i <= n; i++) mn[i] = Min(mn[i - 1], a[i].x);
  for (int i = n; i >= 1; i--) mx[i] = Max(mx[i + 1], a[i].x);
  for (int i = 1; i <= n; i++) is1[i] = mn[i - 1] < a[i].x;
  for (int i = n; i >= 1; i--) is2[i] = mx[i + 1] > a[i].x;
  for (int i = 1; i <= n; i++)
    if (is1[i] && is2[i]) return puts("-1"), 0;
  for (int i = 1; i <= n; i++) {
  	if (mn[i - 1] > mx[i]) l[++tot] = i;
    if (mn[i] > mx[i + 1]) r[tot] = i;
  }
  for (int i = 1; i <= tot; i++) {
  	int cnt00 = 0, cnt01 = 0, cnt10 = 0, cnt11 = 0;
  	for (int j = l[i]; j <= r[i]; j++) {
  	  if (is1[j]) (a[j].typ ? cnt01 : cnt00)++;
  	  if (is2[j]) (a[j].typ ? cnt11 : cnt10)++;
	}
	ans += Min(cnt00 + cnt11, cnt10 + cnt01);
	for (int j = l[i]; j <= r[i]; j++) if (is1[j]) std::swap(a[j].x, a[j].y);
  }
  std::sort(a + 1, a + n + 1, comp);
  for (int i = 1; i < n; i++) if (a[i].x < a[i + 1].x)
    return puts("-1"), 0;
  return std::cout << ans << std::endl, 0;
}