#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

#define int long long

struct Edge {
 int u, v;
 int cap, flow;

 Edge(int u_, int v_, int cap_, int flow_) : u(u_), v(v_), cap(cap_), flow(flow_){}
};

namespace Flow {
 const int INF = 1e15 + 239;
 const int MAX_LOG = 40;

 int n;
 int start;
 int end;

 vector<int> d;
 vector<int> pnt;
 vector<Edge> ed;
 vector<vector<int>> g;

 void clear() {
  d.clear();
  pnt.clear();
  ed.clear();
  g.clear();
 }

 int dfs(int u, int flow) {
  if (flow == 0) {
   return 0;
  }
  if (u == end) {
   return flow;
  }
  for (; pnt[u] < (int)g[u].size(); pnt[u]++) {
   int ind = g[u][pnt[u]];
   int to = ed[ind].v;
   if (d[to] < d[u] + 1) {
    continue;
   }
   int pushed = dfs(to, min(flow, ed[ind].cap - ed[ind].flow));
   if (pushed > 0) {
    ed[ind].flow += pushed;
    ed[ind ^ 1].flow -= pushed;
    return pushed;
   }
  }
  return 0;
 }

 bool bfs(int lim) {
  for (int i = 0; i < n; i++) {
   d[i] = INF;
  }
  d[start] = 0;
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
   int u = q.front();
   q.pop();
   for (auto ind : g[u]) {
    int to = ed[ind].v;
    if (d[to] > d[u] + 1 && ed[ind].flow + lim <= ed[ind].cap) {
     d[to] = d[u] + 1;
     q.push(to);
    }
   }
  }
  return d[end] < INF;
 }

 void init(int n_, int start_, int end_) {
  clear();
  n = n_;
  start = start_;
  end = end_;
  d.resize(n);
  pnt.resize(n);
  g.resize(n);
 }

 void add_edge(int u, int v, int c) {
  int pnt = (int)ed.size();
  ed.push_back(Edge(u, v, c, 0));
  ed.push_back(Edge(v, u, 0, 0));
  g[u].push_back(pnt);
  g[v].push_back(pnt + 1);
 }

 int solve() {
  int ans = 0;
  for (int i = MAX_LOG; i >= 0; i--) {
   while (bfs(1LL << i)) {
    fill(pnt.begin(), pnt.end(), 0);
    while (true) {
     int nw = dfs(start, INF);
     if (nw > 0) {
      ans += nw;
     } else {
      break;
     }
    }
   }
  }
  return ans;
 }
}// namespace Flow

int n, m;
vector<pair<int, pair<int, int>>> ed;

bool check(int pos) {
    Flow::init(2 * n + 2, 2 * n, 2 * n + 1);
    //cout << "pos = " << pos << endl;
    for (int i = 0; i < n; ++i) {
        Flow::add_edge(Flow::start, i, 1);
        Flow::add_edge(i + n, Flow::end, 1);
    }
    for (int i = 0; i <= pos; ++i) {
        Flow::add_edge(ed[i].second.first, ed[i].second.second + n, 1);
    }
    //cout << "pos = " << pos << endl;
    return Flow::solve() == n;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
    cin >> n >> m;
    ed.resize(m);
    for (auto& i : ed) {
        cin >> i.second.first >> i.second.second >> i.first;
        i.second.first--;
        i.second.second--;
    }
    sort(all(ed));
    int l = -1, r = m;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == m) {
        cout << -1 << endl;
    } else {
        cout << ed[r].first << endl;
    }
	return 0;
}