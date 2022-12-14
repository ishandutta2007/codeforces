#include <bits/stdc++.h>
using namespace std;

#define K 8
#define N 1010

vector <int> vec[K][N];
int k, n, rmh[K], V = 0;
int vis[N];

struct dot {
	int x, y;
}blue[K], red[N];

bool inside(dot a, dot b, dot c) {
    if (1ll * a.x * b.y + 1ll * b.x * c.y + 1ll * c.x * a.y - 1ll * a.y * b.x - 1ll * b.y * c.x - 1ll * c.y * a.x == 0) {
		if (1ll * (a.x - b.x) * (b.x - c.x) > 0 || 1ll * (a.y - b.y) * (b.y - c.y) > 0)	return 1;
    }
    return 0;
}

set <int> se;
set <int> ::iterator it;

bool dfs(int x) {
	if (x > k) return se.empty();
    if (se.size() > k - x + 1) return 0;
    if (se.empty()) return 1;
    int c[N], sz = 0;
    for (it = se.begin(); it != se.end(); it ++) c[sz++] = *it;
	for (int i = 0; i < sz; i ++) {
		se.erase(c[i]);
		vis[c[i]] = V;
		int add = 0, limit = k - x - se.size();
		for (int j = 0; j < vec[rmh[x]][c[i]].size(); j ++) {
			int cur = vec[rmh[x]][c[i]][j];
			if (vis[cur] != V) add ++;
			if (add > limit) break;
		}
		if (add <= limit) {
			for (int j = 0; j < vec[rmh[x]][c[i]].size(); j ++) {
				int cur = vec[rmh[x]][c[i]][j];
				if (vis[cur] != V) se.insert(cur);
			}
			if (dfs(x + 1)) return 1;
			for (int j = 0; j < vec[rmh[x]][c[i]].size(); j ++) se.erase(vec[rmh[x]][c[i]][j]);
		}
		se.insert(c[i]);
		vis[c[i]] = 0;
	}
	return 0;
}

int main() {
	int ans = 0;
	scanf("%d %d", &k, &n);
	for (int i = 1; i <= k; i ++) scanf("%d %d", &blue[i].x, &blue[i].y);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &red[i].x, &red[i].y);
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) if (i != j) for (int h = 1; h <= k; h ++) if (inside(blue[h], red[j], red[i])) vec[h][i].push_back(j);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= k; j ++) rmh[j] = j;
        while (1) {
            if (vec[rmh[1]][i].empty()) {
				ans ++;
				break;
            }
            if (vec[rmh[1]][i].size() < k) {
                se.clear();
				for (int j = 0; j < vec[rmh[1]][i].size(); j ++) se.insert(vec[rmh[1]][i][j]);
				V ++;
                if (dfs(2)) {
					ans ++;
					break;
                }
            }
            if (!next_permutation(rmh + 1, rmh + k + 1)) break;
        }
	}
	printf("%d\n", ans);
	return 0;
}