#include <bits/stdc++.h>

using namespace std;

template<typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  void init(int v) {
    fenw.resize(n = v);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= x + 1;
    }
  }

  T query(int x) {
    T res{};
    while (x >= 0) {
      res += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
};

const int N = 234567;

int n, q, f[N], sz[N], tag[N], last[N], c[N][2];
fenwick<int> fenw;
vector<int> adj[N];
bool rev[N];

bool is_root(int x) {
  return c[f[x]][0] != x && c[f[x]][1] != x;
}

void pull(int x) {
  sz[x] = sz[c[x][0]] + sz[c[x][1]] + 1;
}

void rotate(int x) {
  int y = f[x], z = f[y], k = c[y][1] == x;
  if (!is_root(y)) {
    c[z][c[z][1] == y] = x;
  }
  f[c[y][k] = c[x][!k]] = y;
  f[f[c[x][!k] = y] = x] = z;
  pull(y);
  pull(x);
}

void push(int x) {
  if (rev[x]) {
    swap(c[x][0], c[x][1]);
    rev[c[x][0]] ^= 1;
    rev[c[x][1]] ^= 1;
    rev[x] = false;
  }
  if (tag[x]) {
    tag[c[x][0]] = last[c[x][0]] = tag[x];
    tag[c[x][1]] = last[c[x][1]] = tag[x];
    tag[x] = 0;
  }
}

void splay(int x) {
  static int st[N];
  int top = 0;
  st[++top] = x;
  for (int i = x; !is_root(i); i = f[i]) {
    st[++top] = f[i];
  }
  while (top) {
    push(st[top--]);
  }
  for (int y = f[x], z = f[y]; !is_root(x); rotate(x), y = f[x], z = f[y]) {
    if (!is_root(y)) {
      rotate((c[y][1] == x) == (c[z][1] == y) ? y : x);
    }
  }
}

void access(int x, int tt) {
  for (int t = 0; x; t = x, x = f[x]) {
    splay(x);
    c[x][1] = 0;
    pull(x);
    fenw.modify(last[x], -sz[x]);
    last[x] = tag[x] = tt;
    fenw.modify(last[x], sz[x]);
    c[x][1] = t;
    pull(x);
  }
}

void dfs(int x) {
  last[x] = x;
  for (auto y : adj[x]) {
    if (y != f[x]) {
      f[y] = x;
      dfs(y);
      last[x] = max(last[x], last[y]);
    }
  }
  for (auto y : adj[x]) {
    if (y != f[x] && last[x] == last[y]) {
      c[x][1] = y;
      sz[x] = sz[y] + 1;
    }
  }
  fenw.modify(last[x], 1);
}

int query(int x) {
  splay(x);
  push(x);
  return fenw.query(last[x]) - sz[c[x][0]];
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  fenw.init(n + q + 1);
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    sz[i] = 1;
  }
  dfs(n);
  int time = n;
  while (q--) {
    string type;
    cin >> type;
    if (type == "up") {
      int x;
      cin >> x;
      access(x, time);
      splay(x);
      rev[x] ^= 1;
      push(x);
      fenw.modify(last[x], -1);
      c[x][1] = 0;
      tag[x] = last[x] = ++time;
      sz[x] = 1;
      fenw.modify(last[x], 1);
    } else if (type == "when") {
      int x;
      cin >> x;
      cout << query(x) << "\n";
    } else {
      int x, y;
      cin >> x >> y;
      cout << (query(x) < query(y) ? x : y) << "\n";
    }
  }
  return 0;
}