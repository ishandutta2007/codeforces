#include <bits/stdc++.h>

using namespace std;

using cap_t = int;
const cap_t cap_inf = 0x3f3f3f3f;

namespace flow {
struct edge {
  int to, rev;
  cap_t cap;

  edge(int t, cap_t c, int r) {
    to = t;
    cap = c;
    rev = r;
  }
};

vector<vector<edge>> g;
vector<int> ptr, dist;
int n, src, snk;
cap_t ans;

void init(int v, int s, int t) {
  n = v;
  ans = 0;
  src = s;
  snk = t;
  g.clear();
  g.resize(n);
  ptr.resize(n);
  dist.resize(n);
}

void add(int v, int u, cap_t c, cap_t rev_c = 0) {
  g[v].emplace_back(u, c, g[u].size());
  g[u].emplace_back(v, rev_c, g[v].size() - 1);
}

bool bfs() {
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    dist[i] = -1;
  }
  dist[src] = 0;
  q.push(src);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (edge e : g[v]) {
      if (e.cap && !~dist[e.to]) {
        dist[e.to] = dist[v] + 1;
        q.push(e.to);
        if (e.to == snk) {
          return true;
        }
      }
    }
  }
  return false;
}

cap_t dfs(int v, cap_t f) {
  if (v == snk) {
    return f;
  }
  for (int& i = ptr[v]; ~i; --i) {
    edge& e = g[v][i];
    if (e.cap && dist[e.to] == dist[v] + 1) {
      cap_t w = dfs(e.to, min(e.cap, f));
      if (w) {
        e.cap -= w;
        g[e.to][e.rev].cap += w;
        return w;
      }
    }
  }
  return 0;
}

cap_t max_flow() {
  while (bfs()) {
    for (int i = 0; i < n; ++i) {
      ptr[i] = g[i].size() - 1;
    }
    while (true) {
      cap_t flow = dfs(src, cap_inf);
      if (!flow) {
        break;
      }
      ans += flow;
    }
  }
  return ans;
}

vector<bool> min_cut() {
  max_flow();
  vector<bool> res(n);
  for (int i = 0; i < n; ++i) {
    res[i] = !~dist[i];
  }
  return res;
}
}

using flow::src;
using flow::snk;
using flow::add;
using flow::init;
using flow::min_cut;
using flow::max_flow;

struct node {
  node* l = NULL;
  node* r = NULL;
  node* p = NULL;
  int id = -1;
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  node* r = new node();
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    node* v = r;
    for (char c : s[i]) {
      if (c == 'a') {
        if (v->l == NULL) {
          v->l = new node();
        }
        v = v->l;
      } else {
        if (v->r == NULL) {
          v->r = new node();
        }
        v = v->r;
      }
    }
    v->id = i;
  }
  queue<node*> q;
  if (r->l != NULL) {
    r->l->p = r;
    q.push(r->l);
  } else {
    r->l = r;
  }
  if (r->r != NULL) {
    r->r->p = r;
    q.push(r->r);
  } else {
    r->r = r;
  }
  while (!q.empty()) {
    node* v = q.front();
    q.pop();
    if (v->id == -1) {
      v->id = v->p->id;
    }
    if (v->l == NULL) {
      v->l = v->p->l;
    } else {
      v->l->p = v->p->l;
      q.push(v->l);
    }
    if (v->r == NULL) {
      v->r = v->p->r;
    } else {
      v->r->p = v->p->r;
      q.push(v->r);
    }
  }
  vector<vector<bool>> g(n, vector<bool>(n));
  for (int i = 0; i < n; ++i) {
    node* v = r;
    for (char c : s[i]) {
      if (c == 'a') {
        v = v->l;
      } else {
        v = v->r;
      }
      if (v->id != -1) {
        if (v->id != i) {
          g[i][v->id] = true;
        } else if (v->p->id != -1) {
          g[i][v->p->id] = -1;
        }
      }
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][k] && g[k][j]) {
          g[i][j] = true;
        }
      }
    }
  }
  init(n * 2 + 2, n * 2, n * 2 + 1);
  for (int i = 0; i < n; ++i) {
    add(src, i, 1);
    add(i + n, snk, 1);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g[i][j]) {
        add(i, j + n, 1);
      }
    }
  }
  cout << n - max_flow() << "\n";
  vector<bool> cut = min_cut();
  bool first = true;
  for (int i = 0; i < n; ++i) {
    if (!cut[i] && cut[i + n]) {
      if (!first) {
        cout << " ";
      }
      first = false;
      cout << i + 1;
    }
  }
  cout << "\n";
  return 0;
}