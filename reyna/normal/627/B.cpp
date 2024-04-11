//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

#define int long long
const int N = 4e5 + 5;

int read() { int x; cin >> x; return x; }

int pre[N], suf[N], last[N];

int query(int *fen, int m, int res = 0) { m++;
	while (m > 0)
		res += fen[m], m -= m & -m;
	return res;
}

void update(int *fen, int m, int x) { m++;
	while (m < N)
		fen[m] += x, m += m & -m;
}


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k, a, b, q;
	cin >> n >> k >> a >> b >> q;
	while (q--) {
		int c = read();
		if (c == 1) {
			int d = read(), x = read();
			if (last[d] >= a) {
				update(suf, n - d, -a);
			} else {
				update(suf, n - d, -last[d]);
			}
			if (last[d] >= b) {
				update(pre, d, -b);
			} else {
				update(pre, d, -last[d]);
			}
			last[d] = last[d] + x;
			if (last[d] >= a) {
//				cout << d << ' ' << a << ' ' << n - d << " waht \n";
				update(suf, n - d, a);
			} else {
				update(suf, n - d, last[d]);
			}
			if (last[d] >= b) {
				update(pre, d, b);
			} else {
				update(pre, d, last[d]);
			}
		} else {
			int p = read();
//			cerr << endl;
//			cerr << query(pre, p - 1) << ' ' << query(suf, n - (p + k)) << ' ';
			cout << query(pre, p - 1) + query(suf, n - (p + k)) << '\n';
//			cerr << endl;
		}
	}
}