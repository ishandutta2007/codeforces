#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5 + 7;

int sz[N];
int p[N], r[N];

vector <pair <int, int> > d;
int lv[N], rv[N];

int get(int v) {
	return (p[v] == v ? v : get(p[v]));
}

void uni(int v, int u) {
	v = get(v);
	u = get(u);
	if (r[v] == r[u]) {
		r[v]++;
	}
	if (r[v] > r[u]) {
		swap(v, u);
	}
	d.push_back({v, u});
	p[v] = u;
	sz[u] += sz[v];
}

int main() {
	//freopen("F.in", "r", stdin);
	//freopen("F.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		sz[i] = 1;
		p[i] = i;
	}
	vector <pair <int, int> > all;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		all.push_back({x, y});
		uni(x, y);
	}
	int r = get(0);
	lv[r] = 0;
	rv[r] = n - 1;
	for (int i = 1; i < n; i++) {
		int v = d.back().first, u = d.back().second;
		d.pop_back();
		int sz1 = sz[v], sz2 = sz[u] - sz[v];
		sz[u] = sz2;
		p[v] = v;
		lv[v] = lv[u];
		rv[v] = lv[v] + sz1 - 1;
		lv[u] = rv[v] + 1;
	}
	vector <int> res(n, 0);
	for (int i = 0; i < n; i++) {
		res[lv[i]] = i;
	}
	for (int x : res) {
		cout << x + 1 << " ";
	}
	cout << "\n";
}