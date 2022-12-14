//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 0;

int read() { int x; cin >> x; return x; }


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), a = read(), b = read();
	if (n > a * b) {
		cout << -1;
		return 0;
	}
	int x = 1, y = 2;
	rep(i, a) {
		rep(j, b)
			if ((i + j) % 2 == 0) {
				if (x <= n)
					cout << x << ' ';
				else
					cout << 0 << ' ';
				x += 2;
			} else {
				if (y <= n)
					cout << y << ' ';
				else
					cout << 0 << ' ';
				y += 2;
			}
		cout << '\n';
	}
}