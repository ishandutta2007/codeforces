#include <bits/stdc++.h>
using namespace std;

int n, bad;
vector<int> e[100005];
int x[100005], xx;

void dfs(int x, int p, vector<int>& v) {
	int br = 0;
	v.push_back(x);
	for (int y : e[x])
		if (y != p) {
			br++;
			dfs(y, x, v);
		}
	if (br > 1)
		bad = 1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	int c = 1;
	for (int i=2; i<=n; i++)
		if (e[i].size() > e[c].size())
			c = i;

	for (int y : e[c]) {
		vector<int> v;
		dfs(y, c, v);
		x[xx++] = v.back();
	}
	if (bad)
		return cout << "No\n", 0;
	cout << "Yes\n";
	cout << xx << '\n';
	for (int i=0; i<xx; i++)
		cout << c << ' ' << x[i] << '\n';
}