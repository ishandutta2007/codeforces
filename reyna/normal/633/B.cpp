//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e6 + 6;

int read() { int x; cin >> x; return x; }

int a[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m; cin >> m;
	int cnt = 0;
	int res = 0;
	for (int x = 1; x < N; ++x) {
		int j = x;
		while (j % 5 == 0) {
			j /= 5;
			cnt++;
		}
		if (cnt == m) {
			a[res++] = x;
		}
	}
	cout << res << endl;
	for (int i = 0; i < res; ++i)
		cout << a[i] << ' ';
}