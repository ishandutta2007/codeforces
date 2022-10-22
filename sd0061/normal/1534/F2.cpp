#include <bits/stdc++.h>
const int N = 400005;
int n, m, a[N], cnt[N];
char s[N];
int f[N], fall[N];
std::vector<int> row[N];
int getf(int x) {
  return f[x] == x ? x : f[x] = getf(f[x]);
}

void merge(int x, int y) {
  x = getf(x);
  y = getf(y);
  if (x != y) {
    f[x] = y;
  }
}

std::vector<int> e[N], ce[N];

int low[N], ord[N];
int scnt, bel[N];
namespace tarjan {
bool in_stack[N];
std::stack<int> stack;
void dfs(int x, int &&ncnt) {
  low[x] = ord[x] = ++ncnt;
  in_stack[x] = 1;
  stack.push(x);
  for (auto &y : e[x]) {
    if (!ord[y]) {
      dfs(y, std::move(ncnt));
      low[x] = std::min(low[x], low[y]);
    } else if (in_stack[y]) {
      low[x] = std::min(low[x], ord[y]);
    }
  }
  if (low[x] == ord[x]) {
    while (true) {
      int i = stack.top();
      stack.pop();
      in_stack[i] = false;
      bel[i] = scnt;
      if (i == x) {
        break;
      }
    }
    ++scnt;
  }
}
}  // namespace tarjan

void work() {
  scanf("%d%d", &n, &m);
  int len = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s + len);
    len += m;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
  }
  int num = len;
  for (int i = 0; i < num; ++i) {
    f[i] = i;
    fall[i] = num;
    e[i].clear();
  }
  int id = n * m - 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (s[id] == '#' && i + 1 < n && s[id + m] == '#') {
        merge(id, id + m);
      }
      if (s[id] == '#' && j + 1 < m && s[id + 1] == '#') {
        merge(id, id + 1);
      }
      if (i + 1 < n && s[id + m] == '#') {
        fall[id] = id + m;
      } else if (i == n - 1) {
        fall[id] = num;
      } else {
        fall[id] = fall[id + m];
      }

      if (s[id] == '#') {
        ++cnt[j];
        row[j].emplace_back(i);
      }
      id--;
    }
  }
  std::vector<std::pair<int, int>> E;
  auto addEdge = [&](int x, int y) {
    x = getf(x);
    y = getf(y);
    if (x != y) {
      e[x].emplace_back(y);
      E.emplace_back(x, y);
      // printf("%d %d\n", x, y);
    }
  };
  id = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[id] != '#') {
        id++;
        continue;
      }
      if (fall[id] < num) {
        addEdge(id, fall[id]);
      }
      if (j - 1 >= 0 && fall[id - 1] < num) {
        addEdge(id, fall[id - 1]);
      }
      if (j + 1 < m && fall[id + 1] < num) {
        addEdge(id, fall[id + 1]);
      }
      ++id;
    }
  }
  std::fill(ord, ord + num, 0);
  scnt = 0;
  for (int i = 0; i < num; ++i) {
    if (!ord[i] && s[i] == '#' && getf(i) == i) {
      tarjan::dfs(i, 0);
    }
  }
  std::vector<int> sid(scnt);
  std::vector<int> wid(num);
  std::fill(sid.begin(), sid.end(), -1);
  for (int i = 0; i < num; ++i) {
    if (s[i] == '#' && getf(i) == i) {
      int x = bel[i];
      if (!~sid[x]) {
        sid[x] = i;
        wid[i] = x;
      } else {
        merge(i, sid[x]);
      }
    }
  }
  std::vector<std::map<int, int>> h(scnt);
  for (int i = 0; i < num; ++i) {
    if (s[i] == '#') {
      h[wid[getf(i)]][i % m]++;
    }
  }

  // printf("%d\n", scnt);
  std::vector<int> ideg(scnt);
  for (auto &[x, y] : E) {
    if (bel[x] != bel[y]) {
      // printf("- %d %d\n", bel[x], bel[y]);
      ++ideg[bel[y]];
      ce[bel[x]].emplace_back(bel[y]);
    }
  }

  int res = 0;
  std::vector<int> L(scnt), R(scnt);
  for (int i = 0; i < scnt; ++i) {
    if (!ideg[i]) {
      // printf("*%d\n", i);
      int l = h[i].begin()->first;
      L[i] = R[i] = l;
    } else {
      L[i] = 1 << 30;
      R[i] = -1 << 30;
    }
  }
  // for (int i =)
  for (int x = scnt - 1; x >= 0; --x) {
    for (auto &y : ce[x]) {
      L[y] = std::min(L[y], L[x]);
      R[y] = std::max(R[y], R[x]);
    }
    // printf("%d : %d %d\n", x, L[x], R[x]);
  }
  std::vector<std::pair<int, int>> v;
  for (int i = 0; i < m; ++i) {
    if (a[i] > 0) {
      id = row[i][a[i] - 1] * m + i;
      int x = wid[getf(id)];
      v.emplace_back(R[x], L[x]);
    }
  }
  sort(v.begin(), v.end());
  int cur = -1 << 30;
  for (auto &it : v) {
    auto [r, l] = it;
    if (cur < l) {
      ++res;
      cur = r;
    }
  }
  printf("%d\n", res);
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}