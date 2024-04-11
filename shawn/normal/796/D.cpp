#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define pb push_back

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

void wt(int x) {
	if (x >= 10) wt(x / 10);
	putchar(x % 10 + 48);
}

const int N = 3e5 + 10;

struct edge {
	int nxt, to, i;
}e[N << 1];
int head[N], n, m, K, cnt, p, dis[N];
bool app[N];
queue <int> q;
vector <int> ans;

void insert(int u, int v, int i) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v, e[cnt].i = i;
}

int main() {
	n = rd(), m = rd(), K = rd() + 1;
	for (int i = 1; i <= m; i ++) p = rd(), q.push(p), dis[p] = 1;
	for (int i = 1; i < n; i ++) {
		int u = rd(), v = rd();
		insert(u, v, i);
		insert(v, u, i);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (app[e[i].i]) continue;
			app[e[i].i] = 1;
			if (dis[v]) {
				ans.pb(e[i].i);
				continue;
			}
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
	int ed = ans.size();
	wt(ed), putchar(10);
	for (int i = 0; i < ed; i ++) wt(ans[i]), putchar(32);
	return 0;
}