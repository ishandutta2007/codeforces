//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define int long long
const int N = 2e5 + 5;

int read() { int x; cin >> x; return x; }

int q[N], h, t;

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), b = read();
	while (n--) {
		int x = read(), d = read(), res = x + d;
		while (h != t && q[h] <= x)
			h++;
		if (t - h > b) {
			cout << -1 << ' ';
			continue;
		}
		if (t != h)
			res = max(res, q[t - 1] + d);
		q[t++] = res;
		cout << res << ' ';
	}
}