#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, M = 1e6 + 5;
int h, n, m, k, a[N], c[N], now[N];
vector<int> bin[N];
struct Edge { int v, nxt, w; } edge[M];
int head[N], tot, dis[N], vis[N], inq[N];
struct Priority_Queue {
	priority_queue<pair<int, int>> p, q;
	void maintain() { 
//		if(p.size() && q.size())
//			cout << "maintain: " << p.top().first << " " << p.top().second << " " << q.top().first << " " << q.top().second << endl;
		while(p.size() && q.size() && p.top() == q.top()) 
			q.pop(), p.pop(); 
	}
	void push(pair<int, int> x) { 
//		cout << "push: " << x.first << " " << x.second << endl;
		q.push(x), maintain(); 
	}
	void pop(pair<int, int> x) { 
//		cout << "pop: " << x.first << " " << x.second << endl;
		p.push(x), maintain(); 
	}
	pair<int, int> top() { 
		maintain(); 
		if(!q.size()) return {0, 0};
		return q.top(); 
	}
} s;
priority_queue<pair<int, int>> q;

void add(int u, int v, int w) { edge[++tot] = (Edge){ v, head[u], w }, head[u] = tot; }

void Dijkstra() {
	for(int i = 0; i < k; i++) dis[i] = h + 1, vis[i] = 0;
	dis[1] = 1, q.push({-1, 1});
	while(q.size()) {
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v, w = edge[i].w;
			if(dis[u] + w < dis[v]) dis[v] = dis[u] + w, q.push({-dis[v], v});
		}
	}
}

void Update() {
	Dijkstra();
	for(int i = 0; i < k; i++) {
		while(now[i] + 1 < bin[i].size() && dis[i] <= a[bin[i][now[i] + 1]])
			inq[bin[i][now[i] + 1]] = 1, s.push({ c[bin[i][now[i] + 1]], -bin[i][now[i] + 1] }), ++now[i];
	}
}

signed main() {
	h = get(), n = get(), m = get(), k = get();
	for(int i = 1; i <= n; i++) 
		a[i] = get(), c[i] = get(), bin[a[i] % k].push_back(i);
	for(int i = 0; i < k; i++) 
		sort(bin[i].begin(), bin[i].end(), [](int x, int y) { return a[x] > a[y]; }), now[i] = -1;
	Update();
	for(int t = 1; t <= m; t++) {
		int op = get(), x, y;
		if(op == 1) {
			x = get();
			for(int i = 0; i < k; i++) add(i, (x + i) % k, x);
			Update();
		}
		else if(op == 2) {
			x = get(), y = get();
			if(inq[x]) s.pop({ c[x], -x });
			c[x] -= y;
			if(inq[x]) s.push({ c[x], -x });
		}
		else {
			pair<int, int> res = s.top();
			if(res.second) 
				s.pop(res), inq[-res.second] = 0;
			cout << res.first << endl;
		}
	}
	return 0;
}