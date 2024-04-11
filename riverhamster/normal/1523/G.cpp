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

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 100005;
const int INF = 1e9;

struct node {
  int lc, rc;
  int mn;
} t[N * 17 * 17];
int bit[N];
int nc = 0;
int n, m;

void insert(int &x, int l, int r, int p, int v) {
  if (!x) x = ++nc, t[x].mn = v;
  else t[x].mn = min(t[x].mn, v);
  if (l == r) return;
  int mid = (l + r) >> 1;
  p <= mid ? insert(t[x].lc, l, mid, p, v) : insert(t[x].rc, mid + 1, r, p, v);
}

void query(int x, int l, int r, int ql, int &v) {
  if (!x) return;
  if (l >= ql) {
    v = min(v, t[x].mn);
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) query(t[x].lc, l, mid, ql, v);
  query(t[x].rc, mid + 1, r, ql, v);
}

void insert(int l, int r, int v) {
  for (; r <= n; r += r & -r)
    insert(bit[r], 1, n, l, v);
}

int query(int l, int r) {
  int res = INF;
  for (; r; r ^= r & -r)
    query(bit[r], 1, n, l, res);
  return res;
}

vector<int> of_len[N];
pair<int, int> ran[N];

int res = 0;
int output[N];

void solve(int l, int r) {
  if (l > r) return;
  int id = query(l, r);
  if (id == INF) return;
  res += ran[id].second - ran[id].first + 1;
  solve(l, ran[id].first - 1);
  solve(ran[id].second + 1, r);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, m);
  t[0].mn = INF;
  for (int i = 1; i <= m; ++i) {
    read(ran[i].first, ran[i].second);
    of_len[ran[i].second - ran[i].first + 1].push_back(i);
  }
  for (int x = n; x >= 1; --x) {
    for (int id : of_len[x])
      insert(ran[id].first, ran[id].second, id);
    res = 0;
    solve(1, n);
    output[x] = res;
  }
  for (int i = 1; i <= n; ++i)
    printf("%d\n", output[i]);
  return 0;
}