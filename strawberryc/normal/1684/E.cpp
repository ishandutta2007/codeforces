#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

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

const int N = 1e5 + 5, M = N << 2;

int n, k, a[N], cnt[N], sum[N], s1[M], s2[M];

void build(int l, int r, int p) {
  s1[p] = s2[p] = 0;
  if (l == r) return;
  int mid = l + r >> 1;
  build(l, mid, p2); build(mid + 1, r, p3);
}

void change(int l, int r, int pos, int p) {
  if (l == r) return (void) (s1[p]++, s2[p] += pos);
  int mid = l + r >> 1;
  if (pos <= mid) change(l, mid, pos, p2);
  else change(mid + 1, r, pos, p3);
  s1[p] = s1[p2] + s1[p3];
  s2[p] = s2[p2] + s2[p3];
}

int wdj(int l, int r, int k, int p) {
  if (l == r) return k >= s2[p] ? s1[p] : k / l;
  int mid = l + r >> 1;
  if (k <= s2[p2]) return wdj(l, mid, k, p2);
  else return s1[p2] + wdj(mid + 1, r, k - s2[p2], p3);
}

int main() {
  int T; read(T);
  while (T--) {
  	read(n); read(k);
  	for (int i = 1; i <= n; i++) read(a[i]);
  	if (k >= n) {puts("0"); continue;}
  	std::sort(a + 1, a + n + 1);
  	for (int i = 0; i <= n; i++) cnt[i] = 0;
  	for (int i = 1; i <= n; i++) if (a[i] < n) cnt[a[i]]++;
  	build(1, n, 1);
  	int fis = 1;
  	while (fis <= n && a[fis] < n) fis++;
  	for (int i = fis; i <= n;) {
  	  int nxt = i;
  	  while (nxt <= n && a[i] == a[nxt]) nxt++;
  	  change(1, n, nxt - i, 1);
  	  i = nxt;
	}
	sum[0] = cnt[0] > 0;
	for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + (cnt[i] > 0);
	int ans = n;
	for (int i = n; i >= 1; i--) {
	  if (i - sum[i - 1] <= k) ans = Min(ans, s1[1] - wdj(1, n, k, 1));
	  if (cnt[i - 1]) change(1, n, cnt[i - 1], 1);
	}
	printf("%d\n", Min(ans, s1[1] - wdj(1, n, k, 1)));
  }
  return 0;
}