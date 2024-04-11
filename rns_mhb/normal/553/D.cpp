#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, m, k, x, y, d[N], h[N], id, mx, step, sz;
bool vis[N];
double res;
vector <int> V[N], ans;
set <pair <double, int> > S;
set <pair <double, int> > :: iterator it;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	while (k --) {
		scanf("%d", &x);
		vis[x] = 1;
	}
	while (m --) {
		scanf("%d%d", &x, &y);
		V[x].push_back(y);
		V[y].push_back(x);
	}
	for (int i = 1; i <= n; i ++) {
		d[i] = V[i].size();
		h[i] = d[i];
		for (int j = 0; j < V[i].size(); j ++) h[i] -= vis[V[i][j]];
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) S.insert(make_pair(1.0 * h[i] / d[i], i));
	}
	res = 0;
	while (S.size()) {
		it = S.begin();
		id = it -> second;
		if (res < it -> first) {
			mx = step;
			res = it -> first;
		} 
		S.erase(it);
		ans.push_back(id);
		vis[id] = 1;
		for (int j = 0; j < V[id].size(); j ++) {
			int v = V[id][j];
			if (vis[v]) continue;
			else {
				S.erase(make_pair(1.0 * h[v] / d[v], v));
				h[v] --;
				S.insert(make_pair(1.0 * h[v] / d[v], v));
			}
		}
		step ++;
	}
	printf("%d\n", ans.size() - mx);
	for (int i = mx; i < ans.size(); i ++) printf("%d ", ans[i]);
}