#include <bits/stdc++.h>
using namespace std;
#define N 100100

const int inf = 1ll << 30;

priority_queue < pair <int, int> > pq;
int dis[N];
int n, m, a, b, c;
vector <int> v[N], w[N];
map <int, int> mp[N], nxt[N];

int bfs() {
	for (int i = 2; i <= n; i ++) dis[i] = inf;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int x = pq.top().second, t = -pq.top().first;
		pq.pop();
		if (dis[x] != t) continue;
		for (int i = 0; i < v[x].size(); i ++) {
			int y = v[x][i], T = t + w[x][i];
			if (mp[x].count(t)) T += nxt[x][t];
			if (dis[y] > T) {
				dis[y] = T, pq.push(make_pair(-T, y));
			}
		}
	}
	return dis[n] < inf ? dis[n] : -1;
}

int t[N];

int main() {
	scanf("%d %d", &n, &m);
	while (m --) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(b), w[a].push_back(c);
		v[b].push_back(a), w[b].push_back(c);
	}
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &m);
		for (int j = 1; j <= m; j ++) scanf("%d", &t[j]), mp[i][t[j]] = 1;
		for (int j = m; j >= 1; j --) {
			if (mp[i].count(t[j] + 1)) nxt[i][t[j]] = nxt[i][t[j]+1] + 1;
			else nxt[i][t[j]] = 1;
		}
	}
	cout << bfs() << endl;
}