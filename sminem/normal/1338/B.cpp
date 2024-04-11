#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
basic_string<int> e[100005];
int f[2], p[100005];

void dfs1(int x, int p, int d = 0) {
	::p[x] = p;
	if (e[x].size() == 1) {
		f[d % 2]++;
	}
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs1(y, x, d+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v, e[v] += u;
	}

	int x = 1;
	while (e[x].size() == 1) x++;

	dfs1(x, x);
	if (f[1] == 0 || f[0] == 0)
		cout << "1 ";
	else
		cout << "3 ";

	int g = n-1;
	for (int i=1; i<=n; i++) {
		if (e[i].size() == 1)
			continue;
		int w = 0;
		for (int y : e[i]) {
			if (y == p[i])
				continue;
			if (e[y].size() == 1)
				w++;
		}
		g -= w ? w-1 : 0;
	}

	cout << g << '\n';
}