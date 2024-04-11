#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int md = 1e9 + 7;

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
  return x;
}

int mul(int x, int y) {
  return (ll)x * y % md;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m, high;
  scanf("%d %d %d", &n, &m, &high);
  vector<ll> value(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &value[i]);
  }
  int answer = 1;
  for (int i = 0; i < n + high; ++i) {
    answer = mul(answer, 2);
  }
  vector<int> power(n + 1);
  power[0] = 1;
  for (int i = 0; i < n; ++i) {
    power[i + 1] = mul(power[i], 2);
  }
  struct edge_t {
    int u, v;
    ll w;

    bool operator < (const edge_t &b) const {
      return w < b.w;
    }
  };
  vector<edge_t> edge(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &edge[i].u, &edge[i].v);
    --edge[i].u;
    --edge[i].v;
    edge[i].w = value[edge[i].u] ^ value[edge[i].v];
  }
  sort(edge.begin(), edge.end());
  vector<int> p(n), index(n), visit(n);
  int total, timetap = 0;

  auto find = [&](int x) {
    while (x != p[x]) {
      x = p[x] = p[p[x]];
    }
    return x;
  };

  auto insert = [&](int x) {
    if (visit[x] != timetap) {
      visit[x] = timetap;
      index[x] = total++;
    }
  };

  for (int i = 0, j = 0; i < m; i = j) {
    ++timetap;
    total = 0;
    while (j < m && edge[i].w == edge[j].w) {
      ++j;
    }
    for (int k = i; k < j; ++k) {
      insert(edge[k].u);
      insert(edge[k].v);
    }
    for (int k = 0; k < total; ++k) {
      p[k] = k;
    }
    for (int k = i; k < j; ++k) {
      p[find(index[edge[k].u])] = find(index[edge[k].v]);
    }
    int components = n - total;
    for (int k = 0; k < total; ++k) {
      if (find(k) == k) {
        ++components;
      }
    }
    answer = sub(answer, sub(power[n], power[components]));
  }
  printf("%d\n", answer);
  return 0;
}