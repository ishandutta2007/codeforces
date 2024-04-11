#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAXN= 1e5 + 10;
int n;
vector<int> g[MAXN];
int s[MAXN], a[MAXN];

void read() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		p--;
		g[i].push_back(p);
		g[p].push_back(i);
	}
	for (int i = 0; i < n; i++)
		cin >> s[i];
}

void dfs(int v, int p, int sum) {
	if (s[v] == -1) { 
		int m = 1e9;
		for (auto i : g[v]) {
			if (i != p) {
				m = min(m, s[i]);
			}
		}
		if (m == 1e9)
			m = sum;
		s[v] = m;
	}

	a[v] = s[v] - sum;
	for (auto i : g[v]) {
		if (i != p) {
			dfs(i, v, s[v]);
		}
	}
}

int ans;
void run() {
	dfs(0, 0, 0);
	ans = 0;
	/*cout << "a = " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;*/
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			cout << -1 << endl;
			exit(0);
		}
		ans += a[i];
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}