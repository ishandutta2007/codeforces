#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e2 + 10;
int n;
int g[MAXN][MAXN];
int m;
vector<int> a;
void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char x;
			cin >> x;
			g[i][j] = x - '0';
		}
	}
	cin >> m;
	a.resize(m);
	for (auto &i : a){
		cin >> i;
		i--;
	}
}

const int INF = 1e9;
vector<int> ans;

const int MAXM = 1e6 + 10;
int dp[MAXM], p[MAXM];

void run() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (g[i][j] == 1) continue;
			g[i][j] = INF;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	for (int i = 0; i < m; i++)
		dp[i] = INF;

	dp[m - 1] = 0;
	p[m - 1] = -1;
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (j == a[i]) continue;
			if (i - g[j][a[i]] >= 0 && j == a[i - g[j][a[i]]]) {
				if (dp[i - g[j][a[i]]] > dp[i] + 1) {
					dp[i - g[j][a[i]]] = dp[i] + 1;
					p[i - g[j][a[i]]] = i;
				}
			}
		}
	}

	int pos = 0;
	while (pos != -1) {
		ans.push_back(a[pos]);
		pos = p[pos];
	}
}

void write() {
	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i + 1 << " ";
	cout << endl;
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