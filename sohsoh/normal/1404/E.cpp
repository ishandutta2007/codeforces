#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops,fast-math")

using namespace std;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

constexpr int MAXN = 202 * 202;

int n, m, cnt, match[MAXN], C[MAXN];
bool B[300][300], mark[MAXN];
vector<int> adj[MAXN];

inline int vert(int i, int j, int d) {
	i--, j--;
	if (d == 0)
		return (i * m + j) * 2;
	else 
		return (i * (m + 1) + j) * 2 + 1;
}

inline void add_edge(int u, int v) {
	u >>= 1;
	v >>= 1;

	adj[u].push_back(v);
//	adj[v].push_back(u);
}

inline bool valid(int x) {
	if (x & 1) {
		x >>= 1;	
		int j = x % m, i = x / m;
		return B[i + 1][j] && B[i + 1][j + 1];
	} else {
		x >>= 1;
		int j = x % m, i = x / m;
		return B[i][j + 1] && B[i + 1][j + 1];
	}
}

bool try_kuhn(int u){
	mark[u] = true;
	for (int v : adj[u]) {
		if (!match[v] || (!mark[match[v]] && try_kuhn(match[v]))) {
			match[v] = u;
			return true;
		}
	}

	return false;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int t = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			B[i][j] = (c == '#');	
			t += B[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!B[i][j]) continue;
			if (B[i - 1][j] && B[i][j - 1]) add_edge(vert(i, j, 0), vert(i, j, 1));
			if (B[i + 1][j] && B[i][j - 1]) add_edge(vert(i + 1, j, 0), vert(i, j, 1));
			if (B[i - 1][j] && B[i][j + 1]) add_edge(vert(i, j, 0), vert(i, j + 1, 1));
			if (B[i + 1][j] && B[i][j + 1]) add_edge(vert(i + 1, j, 0), vert(i, j + 1, 1));
		}
	}


	for (int i = 0; i < MAXN; i++)
		reverse(all(adj[i]));
	int cnt = 0, k = 0;
	for (int i = 0; i < (n + 3) * (m + 3) * 2; i++) {
		cnt += valid(i);
		if (i & 1) continue;

		memset(mark, false, sizeof mark);
		k += try_kuhn(i / 2);
	}

	k = cnt - k;
	cout << t - k << endl;
	return 0;
}