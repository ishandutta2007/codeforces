#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

namespace flow {
struct edge_t {
  int to, cap, rev;

  edge_t(int t, int c, int r) {
    to = t;
    cap = c;
    rev = r;
  }
};

int n, source, sink, answer;
vector<vector<edge_t>> adj;
vector<int> dist, current;

void init(int v, int s, int t) {
  n = v;
  source = s;
  sink = t;
  answer = 0;
  adj.clear();
  adj.resize(n);
  dist.resize(n);
  current.resize(n);
}

void add(int x, int y, int c) {
  adj[x].push_back(edge_t(y, c, adj[y].size()));
  adj[y].push_back(edge_t(x, 0, adj[x].size() - 1));
}

bool bfs() {
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    dist[i] = -1;
  }
  dist[source] = 0;
  q.push(source);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto e : adj[x]) {
      if (e.cap && !~dist[e.to]) {
        dist[e.to] = dist[x] + 1;
        if (e.to == sink) {
          return true;
        }
        q.push(e.to);
      }
    }
  }
  return false;
}

int dfs(int x, int f) {
  if (x == sink) {
    return f;
  }
  for (int &i = current[x]; ~i; --i) {
    edge_t &e = adj[x][i];
    if (e.cap && dist[e.to] == dist[x] + 1) {
      int w = dfs(e.to, min(e.cap, f));
      if (w) {
        e.cap -= w;
        adj[e.to][e.rev].cap += w;
        return w;
      }
    }
  }
  return 0;
}

int max_flow() {
  while (bfs()) {
    for (int i = 0; i < n; ++i) {
      current[i] = adj[i].size() - 1;
    }
    while (true) {
      int flow = dfs(source, inf);
      if (!flow) {
        break;
      }
      answer += flow;
    }
  }
  return answer;
}
}

using flow::source;
using flow::sink;
using flow::init;
using flow::add;
using flow::max_flow;

struct point_t {
  int x, y;

  point_t(int x = 0, int y = 0): x(x), y(y) {
  }

  point_t operator + (const point_t &b) const {
    return point_t(x + b.x, y + b.y);
  }
  
  point_t operator - (const point_t &b) const {
    return point_t(x - b.x, y - b.y);
  }

  bool operator < (const point_t &b) const {
    return x < b.x || (x == b.x && y < b.y);
  }

  long long sqr() {
    return (long long)x * x + (long long)y * y;
  }
};

long long cross(point_t p, point_t q) {
  return (long long)p.x * q.y - (long long)p.y * q.x;
}

long long dot(point_t p, point_t q) {
  return (long long)p.x * q.x + (long long)p.y * q.y;
}

point_t rotate(point_t p) {
  return point_t(-p.y, p.x);
}

vector<point_t> normalize(vector<point_t> v) {
  int n = v.size(), p = min_element(v.begin(), v.end()) - v.begin();
  vector<point_t> result;
  for (int i = 0; i < n; ++i) {
    result.push_back(v[(p + i) % n]);
  }
  return result;
}

vector<point_t> minkowski_sum(vector<point_t> a, vector<point_t> b) {
  int n = a.size(), m = b.size();
  a = normalize(a);
  b = normalize(b);
  vector<point_t> left(n), right(m);
  for (int i = 0; i < n; ++i) {
    left[i] = a[(i + 1) % n] - a[i];
  }
  for (int i = 0; i < m; ++i) {
    right[i] = b[(i + 1) % m] - b[i];
  }
  vector<point_t> result;
  result.push_back(a[0] + b[0]);
  int i = 0, j = 0;
  while (i < n && j < m) {
    result.push_back(result.back() + (cross(left[i], right[j]) >= 0 ? left[i++] : right[j++]));
  }
  while (i < n) {
    result.push_back(result.back() + left[i++]);
  }
  while (j < m) {
    result.push_back(result.back() + right[j++]);
  }
  return result;
}

bool on_segment(point_t p, point_t q, point_t r) {
  return cross(r - q, r - p) == 0 && dot(r - q, r - p) <= 0;
}

bool cross_ray(point_t p, point_t q, point_t r) {
  p = p - r;
  q = q - r;
  if (p.y > q.y) {
    swap(p, q);
  }
  if (p.y >= 0 || q.y < 0) {
    return false;
  }
  return (long long)p.x * (q.y - p.y) - (long long)p.y * (q.x - p.x) > 0;
}

bool inside(vector<point_t> p, point_t q) {
  int cnt = 0;
  for (int i = 0, n = p.size(); i < n; ++i) {
    if (on_segment(p[i], p[(i + 1) % n], q)) {
      return true;
    }
    if (cross_ray(p[i], p[(i + 1) % n], q)) {
      ++cnt;
    }
  }
  return cnt & 1;
}

bool check(vector<point_t> p, point_t q, int r) {
  int n = p.size();
  for (int i = 0; i < n; ++i) {
    if ((p[i] - q).sqr() < (long long)r * r) {
      return true;
    }
  }
  if (inside(p, q)) {
    return true;
  }
  for (int i = 0; i < n; ++i) {
    point_t s = p[i], t = p[(i + 1) % n];
    if (dot(s - t, q - t) > 0 && dot(t - s, q - s) > 0) {
      long long area = abs(cross(q - s, q - t));
      if (area * area < (s - t).sqr() * r * r) {
        return true;
      }
    }
  }
  return false;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, width;
  scanf("%d %d", &n, &width);
  vector<point_t> p(n);
  int min_x = inf, max_x = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i].x, &p[i].y);
    min_x = min(min_x, p[i].x);
    max_x = max(max_x, p[i].x);
  }
  for (int i = 0; i < n; ++i) {
    p[i].x -= min_x;
  }
  max_x -= min_x;
  vector<point_t> np(n);
  for (int i = 0; i < n; ++i) {
    np[i] = point_t(-p[i].x, -p[i].y);
  }
  p = minkowski_sum(p, np);
  int m;
  scanf("%d", &m);
  vector<point_t> c(m);
  vector<int> r(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", &c[i].x, &c[i].y, &r[i]);
  }
  init(m + 1 << 1, m << 1, m << 1 | 1);
  for (int i = 0; i < m; ++i) {
    add(i << 1, i << 1 | 1, 1);
  }
  for (int i = 0; i < m; ++i) {
    if (c[i].x - r[i] - max_x < 0) {
      add(source, i << 1, inf);
    }
    if (c[i].x + r[i] + max_x > width) {
      add(i << 1 | 1, sink, inf);
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < i; ++j) {
      if (check(p, c[i] - c[j], r[i] + r[j])) {
        add(i << 1 | 1, j << 1, inf);
        add(j << 1 | 1, i << 1, inf);
      }
    }
  }
  printf("%d\n", max_flow());
  return 0;
}