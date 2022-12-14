//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 2e5 + 5;

int read() { int x; cin >> x; return x; }

vector<int> g;
int a[N], mark[N], n;

int check(int pos) {
	if (pos == -1)
		return 0;
	if (pos < n - 1 && pos % 2 == 0 && !(a[pos] < a[pos + 1]))
		return 1;
	if (pos < n - 1 && pos % 2 == 1 && !(a[pos] > a[pos + 1]))
		return 1;
	return 0;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read();
	rep(i, n)
		a[i] = read();
	for (int i = 0; i < n - 1; ++i) {
		if (i % 2 == 0 && !(a[i] < a[i + 1])) {
			g.push_back(i);
			g.push_back(i + 1);
		}
		if (i % 2 == 1 && !(a[i] > a[i + 1])) {
			g.push_back(i);
			g.push_back(i + 1);
		}
	}
	sort(g.begin(), g.end());
	g.resize(unique(g.begin(), g.end()) - g.begin());
	if (g.size() > 10) {
		cout << 0;
		return 0;
	}
	int res = 0;
	for (int x : g)
		mark[x] = 1;
	for (int x : g) {
		rep(i, n) if (!mark[i] || (mark[i] && i > x)) {
			int y = i;
//			cout << x << ' ' << y << endl;
			swap(a[x], a[y]);
			int ok = 1;
			if (check(x) || check(y) || check(x - 1) || check(y - 1))
				ok = 0;
			for (int j : g)
				if (check(j))
					ok = 0;
//			for (int i = 0; i < n - 1; ++i) {
//				if (i % 2 == 0 && !(a[i] < a[i + 1]))
//					ok = 0;
//				if (i % 2 == 1 && !(a[i] > a[i + 1]))
//					ok = 0;
//			}
			res += ok;
			swap(a[x], a[y]);
		}
	}
	cout << res;
}