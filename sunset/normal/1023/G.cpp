#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<pair<int, int>> adj[N], fish[N];
int n, m, now, depth[N];

struct node_t {
  int x, d, v;
  
  node_t(int x, int d, int v, int t = 0):x(x - d * t), d(d), v(v) {
  }

  bool operator < (const node_t &b) const {
    int p = x + now * d, q = b.x + now * b.d;
    return p == q ? d < b.d : p < q;
  }
};

struct collision_t {
  node_t x, y;
  int when;

  collision_t(node_t x, node_t y):x(x), y(y) {
    when = y.x - x.x >> 1;
  }

  bool operator < (const collision_t &b) const {
    if (when != b.when) {
      return when < b.when;
    } else {
      return make_tuple(x.x, x.v, y.x, y.v) < make_tuple(b.x.x, b.x.v, b.y.x, b.y.v);
    }
  }
};

struct info_t {
  set<collision_t> collisions;
  set<node_t> nodes;

  void insert_collision(node_t x, node_t y) {
    if (x.d > 0 && y.d < 0) {
      collisions.insert(collision_t(x, y));
    }
  }

  void erase_collision(node_t x, node_t y) {
    if (x.d > 0 && y.d < 0) {
      collisions.erase(collision_t(x, y));
    }
  }

  void insert(node_t x) {
    if (!x.v) {
      return;
    }
    if (nodes.find(x) != nodes.end()) {
      x.v += nodes.find(x)->v;
      erase(*nodes.find(x));
    }
    auto it = nodes.insert(x).first, next = it;
    ++next;
    if (it != nodes.begin()) {
      auto prev = it;
      --prev;
      if (next != nodes.end()) {
        erase_collision(*prev, *next);
      }
      insert_collision(*prev, x);
    }
    if (next != nodes.end()) {
      insert_collision(x, *next);
    }
  }

  void erase(node_t x) {
    auto it = nodes.find(x), next = it;
    ++next;
    if (next != nodes.end()) {
      erase_collision(x, *next);
    }
    if (it != nodes.begin()) {
      auto prev = it;
      --prev;
      erase_collision(*prev, x);
      if (next != nodes.end()) {
        insert_collision(*prev, *next);
      }
    }
    nodes.erase(it);
  }

  int reset(int x, int y) {
    node_t l(x + 1, -1, y, now), r(x - 1, 1, y, now);
    return max(0, y - max(nodes.find(l) == nodes.end() ? 0 : nodes.find(l)->v, nodes.find(r) == nodes.end() ? 0 : nodes.find(r)->v));
  }

  node_t cancel(node_t x, node_t y) {
    if (x.v > y.v) {
      return node_t(x.x, x.d, x.v - y.v);
    } else {
      return node_t(y.x, y.d, y.v - x.v);
    }
  }
  
  void collide(collision_t x) {
    erase(x.x);
    erase(x.y);
    insert(cancel(x.x, x.y));
  }

  void maintain(int x) {
    while (!collisions.empty() && collisions.begin()->when <= x) {
      collide(*collisions.begin());
    }
  }

  void merge(info_t &b) {
    if (nodes.size() < b.nodes.size()) {
      swap(nodes, b.nodes);
      swap(collisions, b.collisions);
    }
    for (auto x : b.nodes) {
      insert(x);
    }
  }

  int query() {
    int answer = 0;
    for (auto x : nodes) {
      if (x.d > 0) {
        answer += x.v;
      }
    }
    return answer;
  }
} info[N];

void dfs(int x, int parent) {
  for (auto e : adj[x]) {
    int y = e.first, w = e.second;
    if (y != parent) {
      depth[y] = depth[x] + w;
      dfs(y, x);
    }
  }
}

void solve(int x, int parent) {
  for (auto e : adj[x]) {
    int y = e.first, w = e.second;
    if (y != parent) {
      solve(y, x);
      now = -depth[y];
      info[y].maintain(-(depth[x] + 1));
      now = -(depth[x] + 1);
      info[x].merge(info[y]);
    }
  }
  now = -(depth[x] + 1);
  for (auto &e : fish[x]) {
    e.second = info[x].reset(e.first, e.second);
  }
  info[x].maintain(-depth[x]);
  now = -depth[x];
  for (auto e : fish[x]) {
    info[x].insert(node_t(e.first, -1, e.second, now));
    info[x].insert(node_t(e.first, 1, e.second, now));
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    --x;
    --y;
    w <<= 1;
    adj[x].emplace_back(y, w);
    adj[y].emplace_back(x, w);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int day, value, where;
    scanf("%d %d %d", &day, &value, &where);
    day <<= 1;
    --where;
    fish[where].emplace_back(day, value);
  }
  dfs(0, -1);
  solve(0, -1);
  info[0].maintain(INT_MAX);
  printf("%d\n", info[0].query());
  return 0;
}