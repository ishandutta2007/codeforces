#include <bits/stdc++.h>
using namespace std;
#define M 200010
typedef pair <int, int> PII;
vector <PII> v[M];
int n, m, vis[M], dis[M], D, st, en;

void get_diameter() {
	queue <PII> q;
	memset(dis, -1, sizeof(dis));
	int t = 1;
	dis[t] = 0; q.push(PII(t, 0));

	while (!q.empty()) {
		PII p = q.front(); q.pop();
		int x = p.first;
		for (int i = 0; i < v[x].size(); i++) {
			PII P = v[x][i];
			int y = P.first;
			if (dis[y] < 0) {
				dis[y] = dis[x] + P.second; q.push(PII(y, dis[y]));
			}
		}
	}
	int mx = -1;
	for (int i = 1; i <= n; i++) if (dis[i] > mx) mx = dis[i], st = i;

  memset(dis, -1, sizeof(dis));
  dis[st] = 0; q.push(PII(st, 0));
  while (!q.empty()) {
		PII p = q.front(); q.pop();
		int x = p.first;
		for (int i = 0; i < v[x].size(); i++) {
			PII P = v[x][i];
			int y = P.first;
			if (dis[y] < 0) {
				dis[y] = dis[x] + P.second; q.push(PII(y, dis[y]));
			}
		}
	}
	D = -1;
	for (int i = 1; i <= n; i++) if (dis[i] > D) D = dis[i], en = i;
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	int x, y, z;
	for (int i = 0; i < n - 1; i++) {
    int z = 1;
		scanf("%d %d", &x, &y);
		v[x].push_back(PII(y, z)), v[y].push_back(PII(x, z));
	}
	get_diameter();
	printf("%d\n", D);
}