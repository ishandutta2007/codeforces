#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e6 + 7;

vector <int> pr;
vector <int> d(MAXN, -1);

void init() {
	for (int i = 2; i < MAXN; i++) {
		if (d[i] == -1) {
			pr.push_back(i);
			d[i] = pr.size() - 1;
		}
		for (int j = 0; j <= d[i]; j++) {
			if (pr[j] * (ll) i >= MAXN) break;
			d[pr[j] * i] = j;
		}
	}
}

bool isPr(ll x) {
	assert(x < MAXN);
	return pr[d[x]] == x;
}

const int N = 1007;

int gr[N][N];
int sz[N];

void add_edge(int v, int u) {
	assert(!gr[v][u] && v != u);
	gr[v][u] = 1;
	gr[u][v] = 1;
	sz[v]++;
	sz[u]++;
}

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	init();
	int x;
	cin >> x;
	for (int t = x; t <= x; t++) {
		for (int i = 0; i < t; i++) {
			sz[i] = 0;
			for (int j = 0; j < t; j++) {
				gr[i][j] = 0;
			}
		}
		int n = t, sn;
		//cin >> n;
		sn = n;
		int m = 0;
		while (n >= 3) {
			add_edge(n - 1, n - 2);
			add_edge(n - 2, n - 3);
			add_edge(n - 3, n - 1);		
			m += 3;
			n -= 3;
		}
		if (n == 1) {
			add_edge(0, 1);
			add_edge(0, 2);
			m += 2;
		} else if (n == 2) {
			add_edge(0, 1);
			add_edge(0, 2);
			add_edge(1, 3);
			m += 3;
		}
		n = sn;
		if (n == 5) {
			add_edge(0, 4);
			m++;
		}
		if (n == 7) {
			add_edge(0, 4);
			add_edge(0, 5);
			add_edge(0, 6);
			m += 3;
		}
		if (n == 8) {
			m += 4;
			add_edge(0, 5);
			add_edge(0, 6);
			add_edge(0, 7);
			add_edge(1, 4);
		}
		vector <int> good;
		for (int i = 0; i < n; i++) {
			if (sz[i] == 2) {
				good.push_back(i);
			}
		}
		while (!isPr(m) && good.size()) {
			int v = good.back();
			good.pop_back();
			for (int i = 0; i < (int) good.size(); i++) {
				if (!gr[good[i]][v]) {
					add_edge(good[i], v);
					m++;
					swap(good.back(), good[i]);
					good.pop_back();
					break;
				}
			}
		}
		if (isPr(m)) {
			cout << m << "\n";
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (gr[i][j]) {
						cout << i + 1 << " " << j + 1 << "\n";
					}
				}
			}
			return 0;
		}
		cout << t << "\n";
	}
}