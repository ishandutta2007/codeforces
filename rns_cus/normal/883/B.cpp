#include <bits/stdc++.h>
using namespace std;

#define N 200020

vector <int> v[N], w[N];
int r[N], mn[N], deg[N], x, y, ans[N], id[N];
int n, m, k;
queue <int> q;
bitset <N> vis;

bool cmp(int x, int y) {
	return mn[x] > mn[y];
}

struct cmp1{
	bool operator () (const int &x, const int &y) const {
		return mn[x] < mn[y];
	}
};

priority_queue <int, vector <int>, cmp1> q1, q2;


int main() {
	//freopen("in.txt", "r", stdin);

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", r + i);
		vis[r[i]] = true;
	}

	for (int i = 0; i < m; i ++) {
		scanf("%d %d", &x, &y);
		w[x].push_back(y);
		v[y].push_back(x);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		deg[i] = w[i].size();
		if (deg[i] == 0) {
			q.push(i);
			cnt ++;
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		//cout << cur << endl;
		for (auto y : v[cur]) {
			deg[y] --;
			if (deg[y] == 0) { q.push(y); cnt ++; }
		}
		int now = 0;
		for (auto y : w[cur]) {
			if (now < mn[y]) now = mn[y];
		}
		now ++;
		if (now > k) { puts("-1"); return 0; }
		if (r[cur] && now > r[cur]) { puts("-1"); return 0; }
		if (r[cur] == 0) mn[cur] = now;
		else mn[cur] = r[cur];
	}

	if (cnt < n) { puts("-1"); return 0; }

	//for (int i = 1; i <= n; i ++) printf("%d ", mn[i]); puts("");

	for (int i = 1; i <= n; i ++) {
		deg[i] = v[i].size();
		if (!deg[i]) {
			if (r[i]) q2.push(i);
			else q1.push(i);
		}
	}

	int idx, pos = k;
	while (!q1.empty() || !q2.empty()) {

		while (vis[pos] && pos > 0) { pos --; }

		if (q2.empty()) { idx = q1.top(); q1.pop(); }
		else {
			int idd = q2.top();
			if (r[idd] > pos || q1.empty() ) { idx = idd; q2.pop(); }
			else { idx = q1.top(); q1.pop(); }
		}

		///cout << "IDX  " << idx << endl;

		for (auto y : w[idx]) {
			deg[y] --;
			if (!deg[y]) {
				if (r[y]) q2.push(y);
				else q1.push(y);
			}
		}

		if (r[idx] && r[idx] < pos) { puts("-1"); return 0; }

		if (mn[idx] > pos) { ans[idx] = mn[idx]; continue; }

		int now = k + 1;
		for (auto y : v[idx]) {
			if (now > ans[y]) now = ans[y];
		}
		now --;
		if (now < pos) { puts("-1"); return 0; }
		else {
			ans[idx] = pos;
			vis[pos] = true;
		}
	}

	while (vis[pos] && pos > 0) { pos --; }

	if (pos) { puts("-1"); return 0; }

	for (int i = 1; i <= n; i ++) printf("%d ", ans[i]); puts("");
}