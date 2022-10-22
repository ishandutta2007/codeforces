#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, bool> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

set<pll> st[MAXN], F[MAXN];
int ans[MAXN], n, m, H[MAXN];
bool R[MAXN], vis[MAXN], vis2[MAXN];
vector<pair<int, pll>> adj[MAXN];

void check(int ind);

void remove(int ind) {
	if (R[ind]) return;
	R[ind] = true;

	for (pll e : st[ind]) {
		F[e.X].erase({ind, e.Y}); //
		check(e.X);
	}

	st[ind].clear();
}

void check(int ind) {
	if (F[ind].size() == 1) {
		ans[ind] = F[ind].begin() -> Y;
		remove(F[ind].begin() -> X);
	}
}

int dfs_cyc(int v, int ind) {
	vis[v] = true;
	int k = 0;

	for (auto e : adj[v]) {
		if (e.Y.X == ind) continue;
		if (!vis[e.X]) k = max(k, dfs_cyc(e.X, e.Y.X));
		else k = v;
	}

	return k;
}

void dfs(int v, int ind) {
	vis2[v] = true;
	for (auto e : adj[v]) {
		if (e.Y.X == ind) continue;
		if (!vis2[e.X]) {
			ans[e.Y.X] = e.Y.Y;
			H[e.X] = H[v] + 1;
			dfs(e.X, e.Y.X);
		} else if (H[e.X] < H[v]) ans[e.Y.X] = e.Y.Y;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(ans, ans + MAXN, -1);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		bool tmp = false;

		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			
			bool b = (x > 0);
			if (x < 0) x = -x;

			if (!F[x].empty() && F[x].begin() -> X == i) {
				ans[x] = b;
				tmp = true;
			}

			st[i].insert({x, b});
			F[x].insert({i, b});
		}

		if (tmp) remove(i);
	}

	for (int i = 1; i <= m; i++)
		check(i);


	for (int i = 1; i <= m; i++) {
		if (F[i].size() == 2) { //
			pll a = *F[i].begin(), b = *F[i].rbegin();
			if (a.Y == b.Y) {
				ans[i] = a.Y;
				remove(a.X);
				remove(b.X);
			}
		}
	}


	for (int i = 1; i <= m; i++) {
		if (F[i].size() == 2) { //
			pll a = *F[i].begin(), b = *F[i].rbegin();
			adj[a.X].push_back({b.X, {i, b.Y}});
			adj[b.X].push_back({a.X, {i, a.Y}});
		}
	}

	// check removed
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && !R[i]) {
			int v = dfs_cyc(i, 0);
			if (v == 0) return cout << "NO" << endl, 0;
			dfs(v, 0);
		}
	}

	cout << "YES" << endl;
	for (int i = 1; i <= m; i++)
		cout << max(ans[i], 0);
	cout << endl;
	return 0;
}