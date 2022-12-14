//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 3e3 + 3;

int read() { int x; cin >> x; return x; }

char s[N][N];
int n, m, fen[N * 2], add, lft[N][N], rgt[N][N];
set<pair<int, int>> st;

int query(int p, int res = 0) { p++;
	while (p > 0)
		res += fen[p], p -= p & -p;
	return res;
}

void update(int p, int x) { p++;
	while (p < 2 * N)
		fen[p] += x, p += p & -p;
}

int solve(int sum) {
	memset(fen, 0, sizeof fen);
	add = 0;
	st.clear();
	int res = 0;
	for (int i = n - 1; i >= 0; --i) {
		int j = sum - i;
		if (j >= m || j < 0)
			continue;
		update(i, 1);
		st.insert({rgt[i][j] - add, i});
		add--;
		while ((int) st.size()) {
			auto cur = *(st.begin());
			if (s[i][j] != 'z' || cur.first + add < 0) {
				update(cur.second, -1);
				st.erase(cur);
			} else
				break;
		}
//		cout << sum << ' ' << i << ' ' << j << " khabar dad " << endl;
//		for (auto it : st)
//			cout << it.second << ' ';
//		cout << " added " << query(i + lft[i][j] - 1) - query(i - 1) << endl;
//		cout << endl;
		res += query(i + lft[i][j] - 1) - query(i - 1);
	}
	return res;
}

int32_t main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] != 'z')
				lft[i][j] = 0;
			else
				lft[i][j] = 1 + (j? lft[i][j - 1]: 0);
		}
		for (int j = m - 1; j >= 0; --j)
			if (s[i][j] != 'z')
				rgt[i][j] = 0;
			else
				rgt[i][j] = 1 + rgt[i][j + 1];
	}
	long long res = 0;
	for (int i = 0; i < n + m - 1; ++i)
		res += solve(i);
	cout << res;
}