#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

const int N = 2e5 + 5, INF = 0x3f3f3f3f;

int n, m, ecnt, nxt[N], adj[N], go[N], d[N], dis[N];
bool vis[N];

struct wd {
  int u, dis;
  
  friend inline bool operator < (wd a, wd b) {
  	return a.dis > b.dis;
  }
};

std::priority_queue<wd> pq;

void add_edge(int u, int v) {
  nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

int main() {
  int x, y;
  read(n); read(m);
  while (m--) read(x), read(y), add_edge(y, x), d[x]++;
  memset(dis, INF, sizeof(dis)); dis[n] = 0;
  pq.push((wd) {n, 0});
  while (!pq.empty()) {
  	wd t = pq.top(); pq.pop();
  	if (vis[t.u]) continue;
  	int u = t.u; vis[u] = 1;
  	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e]) {
  	  int td = dis[u] + (d[v]--);
  	  if (td < dis[v]) dis[v] = td;
  	  pq.push((wd) {v, td});
	}
  }
  return std::cout << dis[1] << std::endl, 0;
}