//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e5 + 5;

int read() { int x; cin >> x; return x; }

pii row[N], col[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read(), q = read();
	rep(i, N)
		row[i] = col[i] = {0, q + 1};
	while (q--) {
		int c = read();
		if (c == 1) {
			int r = read() - 1, a = read();
			row[r] = {a, q};
		} else {
			int c = read() - 1, a = read();
			col[c] = {a, q};
		}
	}
	rep(i, n) {
		rep(j, m) {
			if (row[i].second < col[j].second)
				cout << row[i].first << ' ';
			else
				cout << col[j].first << ' ';
		}
		cout << '\n';
	}
}