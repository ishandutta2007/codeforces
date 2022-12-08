#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int start[maxn+1];
int endi[maxn+1];
int colors[maxn+1];
int curcount[maxn+1];
vector<int> dfs;
vector<vector<int>> adj;
int BIT[maxn+2];
int n;
int totcolors;

void recurse(int u, int par) {
	// cout << "recurse:  " << u << "   " << par << endl;
	dfs.push_back(u);
	start[u] = dfs.size()-1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == par) continue;
		// cout << "here:  " << v << endl;
		recurse(v, u);
	}
	endi[u] = dfs.size()-1;
}

void insert(int u, int diff) {
	while (u <= maxn+1) {
		BIT[u] += diff;
		u += u & (-u);
	}
}

int getval(int u) {
	int sum = 0;
	while (u > 0) {
		sum += BIT[u];
		u -= u&(-u);
	}
	return sum;
}

void adds(int u) {
	curcount[u]++;
	// cout << "curcount:  " << curcount[u] << endl;
	insert(curcount[u]+1, 1);
	insert(curcount[u], -1);
}

void sub(int u) {
	curcount[u]--;
	insert(curcount[u]+1, 1);
	insert(curcount[u]+2, -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> n >> m;
	bool seen[maxn+1];
	for (int i = 0; i <= maxn; i++) {
		seen[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		cin >> colors[i];
		seen[colors[i]] = true;
	}
	for (int i = 0; i <= n;i++) {
		vector<int> b;
		adj.push_back(b);
	}
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	recurse(1, -1);
	vector<tuple<int, int, int, int, int>> queries;
	int v, k;
	int st, en, bucket;
	for (int i = 0; i < m; i++) {
		cin >> v >> k;
		st = start[v];
		en = endi[v];
		bucket = st/sqrt(n);
		queries.push_back(tuple<int, int, int, int, int>(bucket, en, st, i, k));
	}
	int anses[m];
	sort(queries.begin(), queries.end());
	for (int i = 0; i <= maxn; i++) {
		if (seen[i]) totcolors++;
		curcount[i] = 0;
		BIT[i] = 0;
	}
	for (int i = 0; i <= maxn; i++) {
		if (seen[i]) insert(1, 1);
	}
	int l, r, la, ra, index;
	for (int i = 0; i < m; i++) {
		l = get<2>(queries[i]);
		r = get<1>(queries[i]);
		k = get<4>(queries[i]);
		// cout << "qu:  " << l << " " << r << endl;
		index = get<3>(queries[i]);
		if (i == 0) {
			for (int j = l; j <= r; j++) {
				adds(colors[dfs[j]]);
			}
			la = l;
			ra = r;
		}
		while (la > l) {
			la--;
			adds(colors[dfs[la]]);
		}
		while (ra < r) {
			ra++;
			adds(colors[dfs[ra]]);
		}
		while (la < l) {
			sub(colors[dfs[la]]);
			la++;
		}
		while (ra > r) {
			sub(colors[dfs[ra]]);
			ra--;
		}
		anses[index] = totcolors - getval(k);
		// cout << "val:  " << getval(k) << endl;
	}
	for (int i = 0; i < m; i++) {
		cout << anses[i] << '\n';
	}
	// cin >> ra;

}