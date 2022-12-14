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

int xx[N], a[N], b[N], c[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), k = read();
	rep(i, n + 1) {
		xx[i] = read();
		if (xx[i] < 0)
			b[i] += abs(xx[i]);
		else
			a[i] += abs(xx[i]);
	}
	rep(i, N - 1) {
		a[i + 1] += a[i] >> 1;
		a[i] &= 1;
		b[i + 1] += b[i] >> 1;
		b[i] &= 1;
	}
	for (int i = N - 1; i >= 0; --i) {
		if (a[i] != b[i]) {
			if (a[i] < b[i]) {
				rep(j, n + 1)
					xx[j] *= -1;
				rep(j, N)
					swap(a[j], b[j]);
			}
			int r = i;
			c[i] = 1;
			for (int j = i - 1; j >= 0; --j) {
				if (a[j] > b[j]) {
					r = j;
					c[j] = 1;
				}
				if (a[j] < b[j]) {
					for (int k = j; k < r; ++k)
						c[k] = 1;
					c[r] = 0;
					r = j;
				}
			}
			break;
		}
	}
	int fst = 0;
	rep(i, N) if (c[i]) {
		fst = i;
		break;
	}
	int p = 0;
	int res = 0;
	for (int i = N - 1; i >= 0; --i) {
		p <<= 1;
		p += c[i];
		if (p > 1e15)
			break;
		if (i <= fst && i <= n) {
			if (abs(xx[i] - p) <= k) {
				if (i != n || xx[i] - p != 0)
					res++;
			}
		}
	}
	cout << res << endl;
}