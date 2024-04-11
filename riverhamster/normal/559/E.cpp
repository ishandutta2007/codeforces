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

void upmax(int &x, int y) { if (x < y) x = y; }

const int N = 105;

struct line {
  int p, l, r;
} l[N];
int f[N][N * 3];
vector<int> pos;

int dist(int i, int j) {
  return abs(pos[i] - pos[j]);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(l[i].p, l[i].l);
    l[i].r = l[i].p + l[i].l;
    l[i].l = l[i].p - l[i].l;
    pos.emplace_back(l[i].p);
    pos.emplace_back(l[i].l);
    pos.emplace_back(l[i].r);
  }
  sort(pos.begin(), pos.end());
  pos.erase(unique(pos.begin(), pos.end()), pos.end());
  auto norm = [&](int &x) { x = lower_bound(pos.begin(), pos.end(), x) - pos.begin(); };
  for (int i = 1; i <= n; ++i)
    norm(l[i].l), norm(l[i].p), norm(l[i].r);
  sort(l + 1, l + 1 + n, [](const line &a, const line &b) { return a.p < b.p; });

  for (int i = 1; i <= n; ++i) {
    copy_n(f[i - 1], pos.size(), f[i]);
    upmax(f[i][l[i].r], f[i - 1][l[i].p] + dist(l[i].p, l[i].r));
    int R = l[i].p;
    for (int j = i - 1; j >= 0; --j) {
      upmax(f[i][R], f[j][l[i].l] + dist(l[i].l, R));
      if (j) R = max(R, l[j].r);
    }
    for (int j = pos.size() - 1; j; --j)
      upmax(f[i][j - 1], f[i][j] - dist(j, j - 1));
    for (int j = 0; j < (int)pos.size() - 1; ++j)
      upmax(f[i][j + 1], f[i][j]);
  }
  printf("%d\n", f[n][pos.size() - 1]);
  return 0;
}