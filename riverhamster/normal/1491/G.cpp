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

const int N = 200005;
int a[N];
bool vis[N], st[N];
vector<int> cycles;
vector<pair<int, int>> res;

void op(int x, int y) {
  res.emplace_back(x, y);
  st[x] ^= 1; st[y] ^= 1;
  swap(a[x], a[y]), swap(st[x], st[y]);
}
void solve(int x, int y) {
  op(x, y);
  while (!st[a[x]]) op(x, a[x]);
  while (!st[a[y]]) op(y, a[y]);
  assert(a[y] == x); op(x, y);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    cycles.emplace_back(i);
    int x = i;
    while (!vis[x]) vis[x] = true, x = a[x];
  }
  for (size_t i = 0; i < cycles.size() - 1; i += 2)
    solve(cycles[i], cycles[i + 1]);
  if (cycles.size() & 1) {
    int s = cycles.back(), siz = 1;
    int x = a[s];
    while (x != s) ++siz, x = a[x];
    if (siz == 2) {
      int p = -1;
      for (int i = 1; i <= n; ++i)
        if (a[i] == i) { p = i; break; }
      assert(p != -1);
      int t = a[s];
      op(p, s); op(t, p); op(p, s);
    }
    else if (siz != 1) {
      int t = a[s], u = a[t];
      op(s, t); op(t, u);
      while (!st[a[s]]) op(s, a[s]);
      while (!st[a[t]]) op(t, a[t]);
      assert(a[t] == s); op(t, a[t]);
    }
  }
  printf("%u\n", res.size());
  for (const auto &p : res) printf("%d %d\n", p.first, p.second);
  for (int i = 1; i <= n; ++i) assert(a[i] == i);
  for (int i = 1; i <= n; ++i) assert(!st[i]);
  return 0;
}