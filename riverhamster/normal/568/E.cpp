#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 100005;

int a[N], b[N];
int f[N];
pair<int, int> pre[N], pos[N];
int lis[N];
bool vis[N];
int len = 0;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  read(m);
  for (int i = 1; i <= m; ++i) read(b[i]);
  sort(b + 1, b + 1 + m);
  for (int i = 1; i <= n; ++i) {
    if (a[i] != -1) {
      int p = lower_bound(f + 1, f + 1 + len, a[i]) - f;
      if (p > len) len = p;
      lis[i] = p;
      f[p] = a[i];
      pos[p] = {i, 1};
      pre[i] = pos[p - 1];
    }
    else {
      int p = len;
      for (int j = m; j >= 1; --j) {
        while (p && f[p] >= b[j]) --p;
        lis[i] = max(lis[i], p + 1);
        f[p + 1] = b[j];
        if (p >= len) len = p + 1;
        pos[p + 1] = {i, j};
      }
    }
  }
  int LEN = len;
  for (auto p = pos[len]; p.first; --LEN) {
    if (a[p.first] == -1) {
      a[p.first] = b[p.second];
      vis[p.second] = true;
      bool flag = false;
      for (int i = p.first - 1; i >= 1; --i) {
        if (lis[i] == LEN - 1 && a[i] != -1 && a[i] < b[p.second]) {
          p = {i, 1};
          flag = true;
          break;
        }
      }
      if (!flag) {
        if (LEN == 1) break;
        for (int i = p.first - 1; i >= 1; --i)
          if (a[i] == -1) {
            p.first = i;
            while (b[p.second - 1] == b[p.second]) --p.second;
            --p.second;
            break;
          }
      }
    }
    else {
      assert(lis[p.first] <= lis[pre[p.first].first] + 1);
      p = pre[p.first];
    }
  }
  int p = 1;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == -1) {
      while (vis[p]) ++p;
      a[i] = b[p++];
    }
  }
  for (int i = 1; i <= n; ++i)
    printf("%d%c", a[i], " \n"[i == n]);
  return 0;
}