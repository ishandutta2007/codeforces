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

int b[N], a[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read();
	int m = 0;
	for (int i = 0; i < n; ++i) {
		a[i] = read();
	}
	for (int i = 1; i < n; ++i) {
		b[m++] = a[i - 1];
		if (__gcd(a[i], a[i - 1]) != 1) {
			b[m++] = 1;
		}
	}
	b[m++] = a[n - 1];
	cout << m - n << endl;
	rep(i, m)
		cout << b[i] << ' ';
}