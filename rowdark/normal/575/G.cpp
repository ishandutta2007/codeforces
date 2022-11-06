#include<deque>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

vector<pair<int, int> > edge[N];

int dis[N], rdis[N], fa[N], rfa[N], mins[N];

int vis[N], stamp;

int n, m;

bool byrDis(int i, int j) {
	return rdis[i] < rdis[j];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, len;
		scanf("%d%d%d", &u, &v, &len);
		edge[u].push_back(make_pair(v, len));
		edge[v].push_back(make_pair(u, len));
	}
	for (int i = 0; i < n; ++i) {
		dis[i] = -1;
	}
	dis[n - 1] = 0;
	rdis[n - 1] = 0;
	deque<int> q, qq;
	q.push_back(n - 1);
	while (q.size()) {
		int u = q.front();
		qq.push_back(u);
		q.pop_front();
		for (int i = 0; i < (int)edge[u].size(); ++i) {
			int v = edge[u][i].first, d = edge[u][i].second;
			if (dis[v] == -1 && d == 0) {
				rfa[v] = u;
				rdis[v] = rdis[u] + 1;
				dis[v] = 0;
				q.push_back(v);
			}
		}
	}
	while (qq.size()) {
		int u = qq.front();
		qq.pop_front();
		for (int i = 0; i < (int)edge[u].size(); ++i) {
			int v = edge[u][i].first, d = edge[u][i].second;
			if (dis[v] == -1) {
				rfa[v] = u;
				rdis[v] = rdis[u] + 1;
				dis[v] = dis[u] + 1;
				qq.push_back(v);
			}
		}
	}
	/*
	for (int i = 0; i < n; ++i) {
		printf("%d ", dis[i]);
	}
	printf("\n");
	*/
	for (int i = 0; i < n; ++i) {
		mins[i] = 10;
	}
	vector<int> bucket[2][10];
	vector<bool> equal[2][10];
	int cur = 0;
	bucket[cur][0].push_back(0);
	mins[0] = 0;
	int target = -1;
	bool flag = false;
	while (!flag) {
		int nxt = cur ^ 1;
		for (int i = 0; i < 10; ++i) {
			bucket[nxt][i].clear();
			equal[nxt][i].clear();
		}
		for (int i = 0; i < 10 && !flag; ++i) {
			for (int j = 0; j < (int)bucket[cur][i].size() && !flag; ++j) {
				int k = j;
				vector<int> type;
				type.push_back(bucket[cur][i][j]);
				while (k + 1 < (int)bucket[cur][i].size() && equal[cur][i][k]) {
					type.push_back(bucket[cur][i][++k]);
				}
				sort(type.begin(), type.end(), byrDis);
				j = k;
				++stamp;
				for (int _ = 0; _ < (int)type.size(); ++_) {
					int u = type[_];
					if (i == mins[u]) {
						vis[u] = stamp;
					}
				}
				for (int _ = 0; _ < (int)type.size() && !flag; ++_) {
					int u = type[_];
					if (i != mins[u]) {
						continue;
					}
					if (dis[u] == 0) {
						target = u;
						flag = true;
						break;
					}
					for (int k = 0; k < (int)edge[u].size(); ++k) {
						int v = edge[u][k].first, d = edge[u][k].second;
						if (dis[v] == dis[u] - 1) {
							if (d < mins[v]) {
								fa[v] = u;
								mins[v] = d;
								if (bucket[nxt][d].size()) {
									int last = bucket[nxt][d].back();
									equal[nxt][d].push_back(vis[fa[last]] == stamp);
								}
								bucket[nxt][d].push_back(v);
							}
						}
					}
				}
			}
		}
		cur = nxt;
	}
	/*
	   for (int i = 0; i < n; ++i) {
	   printf("%d ", mins[i]);
	   }
	   printf("\n");
	 */
	vector<int> path;
	int u = target;
	string ans;
	while (u) {
		path.push_back(u);
		ans += mins[u] + '0';
		u = fa[u];
	}
	path.push_back(0);
	reverse(path.begin(), path.end());
	u = target;
	while (u != n - 1) {
		u = rfa[u];
		path.push_back(u);
	}
	if (dis[0] == 0) {
		puts("0");
	} else {
		puts(ans.c_str());
	}
	printf("%d\n", (int)path.size());
	for (int i = 0; i < (int)path.size(); ++i) {
		printf("%d%c", path[i], i == (int)path.size() - 1 ? '\n' : ' ');
	}
	return 0;
}