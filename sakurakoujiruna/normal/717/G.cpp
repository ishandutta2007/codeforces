#include <bits/stdc++.h>
using namespace std;

const int N = 511, M = 2e5L + 11;

struct edge {
	int u, v, f, c;
}e[M];
int cnt = 0;
int first[N], nxt[M];
void add(int u, int v, int f, int c) {
	e[cnt] = {u, v, f, c};
	nxt[cnt] = first[u]; first[u] = cnt ++;
	e[cnt] = {v, u, 0, -c};
	nxt[cnt] = first[v]; first[v] = cnt ++;
}

int f[N], p[N];
bool vis[N];
bool spfa(int s, int t) {
	queue <int> q;
	memset(vis, 0, sizeof vis);
	memset(f, 0x3f, sizeof f);
	q.push(s); vis[s] = 1; f[s] = 0;
	while(!q.empty()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for(int i = first[x]; i != -1; i = nxt[i]) if(e[i].f) {
			if(f[e[i].v] > f[x] + e[i].c) {
				f[e[i].v] = f[x] + e[i].c;
				p[e[i].v] = i;
				if(!vis[e[i].v]) {
					vis[e[i].v] = 1;
					q.push(e[i].v);
				}
			}
		}
	}
	return f[t] != 0x3f3f3f3f;
}

int mcmf(int s, int t) {
	int r = 0;
	while(spfa(s, t)) {
		p[s] = -1;
		int x = 1e9L;
		for(int i = p[t]; i != -1; i = p[e[i].u])
			x = min(x, e[i].f);
		for(int i = p[t]; i != -1; i = p[e[i].u]) {
			e[i].f -= x;
			e[i ^ 1].f += x;
		}
		r += x * f[t];
	}
	return r;
}

int main() {
	ios :: sync_with_stdio(false);
	memset(first, -1, sizeof first);
	memset(nxt, -1, sizeof nxt);
	int n; cin >> n;
	string s; cin >> s;
	int m; cin >> m;
	while(m --) {
		string t; int p;
		cin >> t >> p;
		for(int i = 1; i <= n; i ++)
			if(s.substr(i - 1, t.size()) == t) {
				//cout << i << ' ' << i + t.size() << ' ' << p << '\n';
				add(i, i + t.size(), 1, -p);
			}
	}
	int x; cin >> x;
	for(int i = 0; i <= n; i ++)
		add(i, i + 1, x, 0);
	cout << -mcmf(0, n + 1) << '\n';
}