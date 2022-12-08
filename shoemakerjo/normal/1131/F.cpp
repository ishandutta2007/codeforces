#include <bits/stdc++.h>

using namespace std;

const int maxn = 150010;
int n;

vector<int> ch[maxn*3];

int par[maxn*3];

int findset(int u) {
	if (par[u] == u) return u;
	return par[u]  = findset(par[u]);
}


void dfs(int u) {
	if (u <= n) cout << u << " ";
	for (int v : ch[u]) {
		dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int cv = n;

	for (int i =1; i <= 3*n; i++) {
		par[i] = i;
	}

	int x, y;
	for (int i = 0 ; i < n-1; i++) {
		++cv;
		cin >> x >> y;
		x = findset(x);
		y = findset(y);

		ch[cv].push_back(x);
		ch[cv].push_back(y);
		par[x] = cv;
		par[y] = cv;
	}

	dfs(cv);
	cout << endl;
}