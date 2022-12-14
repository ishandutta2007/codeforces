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

int sum[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), k = read();
	string s; cin >> s;
	rep(i, N - 1)
		sum[i + 1] = sum[i] + (i < n? (s[i] == '0'): 0);
	int res = n;
	rep(i, n) if (s[i] == '0') {
		int bl = 0, br = n;
		while (bl < br - 1) {
			int bm = bl + br >> 1;
			int l = i - bm, r = i + bm + 1;
			l = max(l, 0);
			if (sum[r] - sum[l] >= k + 1)
				br = bm;
			else
				bl = bm;
		}
		res = min(res, br);
	}
	cout << res << endl;
}