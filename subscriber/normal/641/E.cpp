#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, fenw[N];

void modify(int x, int v) {
  while (x <= n) {
    fenw[x] += v;
    x = (x | (x - 1)) + 1;
  }
}

int find_sum(int x) {
  int v = 0;
  while (x > 0) {
    v += fenw[x];
    x &= x - 1;
  }
  return v;
}

pair <int, int> e[N], f[N];
int res[N];
int type[N], T[N], x[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", type + i, T + i, x + i);
    e[i] = make_pair(T[i], i);
    f[i] = make_pair(x[i], i);
    res[i] = -1;
  }
  sort(e, e + n);
  for (int i = 0; i < n; i++) {
    T[e[i].second] = i + 1;
  }
  sort(f, f + n);
  for (int i = 1; i <= n; i++) {
    fenw[i] = 0;
  }
  int beg = 0;
  while (beg < n) {
    int end = beg;
    while (end + 1 < n && f[end + 1].first == f[end].first) {
      end++;
    }
    for (int k = beg; k <= end; k++) {
      int i = f[k].second;
      if (type[i] == 1) {
        modify(T[i], 1);
      }
      if (type[i] == 2) {
        modify(T[i], -1);
      }
      if (type[i] == 3) {
        res[i] = find_sum(T[i]);
      }
    }
    for (int k = beg; k <= end; k++) {
      int i = f[k].second;
      if (type[i] == 1) {
        modify(T[i], -1);
      }
      if (type[i] == 2) {
        modify(T[i], 1);
      }
    }
    beg = end + 1;
  }
  for (int i = 0; i < n; i++) {
    if (type[i] == 3) {
      printf("%d\n", res[i]);
    }
  }
  return 0;
}