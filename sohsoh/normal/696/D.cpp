#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll SIG = 26;

int nxt[MAXN][SIG], F[MAXN], n, val[MAXN], sz, R[MAXN];
ll l;

struct matrix {
	int n, m;
	vector<vector<ll>> a;

	matrix() {}
	matrix(int n, int m): n(n), m(m) {
		a.resize(n);
		for (int i = 0; i < n; i++)
			a[i].resize(m, -1);
	}

	matrix operator* (const matrix& b) {
		matrix ans(n, b.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				for (int k = 0; k < m; k++) {
					if (a[i][k] < 0 || b.a[k][j] < 0) continue;
					ans.a[i][j] = max(ans.a[i][j], a[i][k] + b.a[k][j]);	
				}
			}
		}

		return ans;
	}
};

inline int addTrie(string s) {
	int v = 0;
	for (char c : s) {
		if (nxt[v][c - 'a']) v = nxt[v][c - 'a'];
		else v = nxt[v][c - 'a'] = ++sz;
	}

	return v;
}

inline void buildAho() {
	queue<int> q;
	for (int i = 0; i < SIG; i++)
		if (nxt[0][i])
			q.push(nxt[0][i]);

	while (!q.empty()) {
		int v = q.front();
		q.pop();	
		val[v] += val[F[v]];

		for (int i = 0; i < SIG; i++) {
			if (nxt[v][i]) {
				F[nxt[v][i]] = nxt[F[v]][i];
				q.push(nxt[v][i]);
			} else nxt[v][i] = nxt[F[v]][i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> l;
	for (int i = 1; i <= n; i++) cin >> R[i];

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		val[addTrie(s)] += R[i];
	}

	buildAho();
	sz++;
	matrix ans(sz, sz), A(sz, sz);
	ans.a[0][0] = 0;

	for (int i = 0; i < sz; i++)
		for (int j = 0; j < SIG; j++)
			if (nxt[i][j])
				A.a[i][nxt[i][j]] = val[nxt[i][j]];
	while (l) {
		if (l & 1) ans = ans * A;
		l >>= 1;
		A = A * A;
	}

	ll fans = 0;
	for (int i = 0; i < sz; i++)
		fans = max(fans, ans.a[0][i]);
	cout << fans << endl;
	return 0;
}