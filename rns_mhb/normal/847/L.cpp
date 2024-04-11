#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, sz[N], del[N];
char buf[N<<4];
set <int> s[N][N];
set <int> :: iterator it;
vector < pair <int, int> > ans;

vector <int> v[N];

int dfs(int x, int p = 0) {
	int rlt = 1;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (y != p) rlt += dfs(y, x);
	}
	return rlt;
}

set <int> nodes;
vector < set <int> > org[N], cur;

void DFS(int x, int p = 0) {
	nodes.insert(x);
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (y != p) DFS(y, x);
	}
}

bool judge() {
	for (int i = 0; i < ans.size(); i ++) {
		int x = ans[i].first, y = ans[i].second;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (dfs(1) != n) return 0;
	for (int i = 1; i <= n; i ++) {
		cur.clear();
		for (int j = 0; j < v[i].size(); j ++) {
			nodes.clear();
			DFS(v[i][j], i);
			cur.push_back(nodes);
		}
		sort(cur.begin(), cur.end());
		sort(org[i].begin(), org[i].end());
		if (cur != org[i]) return 0;
	}
	return 1;
}

int main() {
//	freopen("l.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%s", buf);
		int len = strlen(buf);
		buf[len] = '-';
		for (int j = 0; j < len;) {
			int cnt = 0;
			while (buf[j] != ':') cnt = cnt * 10 + buf[j] - '0', j ++;
			sz[i] ++;
			j ++;
			for (int k = 0; k < cnt; k ++) {
				int val = 0;
				while (buf[j] != ',' && buf[j] != '-') val = val * 10 + buf[j] - '0', j ++;
				s[i][sz[i]].insert(val);
				j ++;
			}
		}
		for (int j = 1; j <= sz[i]; j ++) org[i].push_back(s[i][j]);
	}
	for (int step = n - 1; step; step --) {
		int pivot = 0;
		for (int i = 1; i <= n; i ++) if (!del[i] && sz[i] == 1) pivot = i;
		if (!pivot) return puts("-1"), 0;
		del[pivot] = 1;
		int pa = 0;
		for (int i = 1; i <= n; i ++) if (!del[i]) {
			bool find = 0;
			for (int j = 1; j <= sz[i]; j ++) {
				if (s[i][j].size() == 1 && *s[i][j].begin() == pivot) {
					find = 1; break;
				}
			}
			if (find) {
				pa = i; break;
			}
		}
		if (!pa) return puts("-1"), 0;
		ans.push_back(make_pair(pivot, pa));
		for (int i = 1; i <= n; i ++) if (!del[i]) {
			for (int j = 1; j <= sz[i]; j ++) {
				it = s[i][j].find(pivot);
				if (it != s[i][j].end()) {
					s[i][j].erase(it);
					if (s[i][j].empty()) {
						if (j == sz[i]) sz[i] --;
						else swap(s[i][j], s[i][sz[i]]), j --, sz[i] --;
					}
					break;
				}
			}
		}
	}
	if (judge()) {
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i ++) printf("%d %d\n", ans[i].first, ans[i].second);
	}
	else puts("-1");
	return 0;
}