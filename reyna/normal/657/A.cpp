//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)


int read() { int x; cin >> x; return x; }


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), d = read(), h = read(), cnt = 2;
	if (h * 2 < d || h > d) {
		cout << -1 << endl;
		return 0;
	}
	if (d == 1 && h == 1) {
		if (n != 2) {
			cout << -1 << endl;
			return 0;
		}
		cout << 1 << ' ' << 2 << endl;
		return 0;
	}
	rep(i, d - h) {
		cout << cnt - 1 << ' ' << cnt << '\n';
		cnt++;
	}
	int last = 1;
	cout << 1 << ' ' << cnt << '\n';
	cnt++;
	rep(i, h - 1) {
		last = cnt - 1;
		cout << cnt - 1 << ' ' << cnt << '\n';
		cnt++;
	}
	while (cnt != n + 1)
		cout << last << ' ' << cnt << '\n', cnt++;
	
}