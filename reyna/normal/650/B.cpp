//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define int long long
const int N = 5e5 + 5;
int read() { int x; cin >> x; return x; }

string s;
int suf[N], pre[N], n, a, b, t;
bool check(int lim) {
	rep(en, lim) {
		int need = lim + (lim - 1) * a + min(lim - en - 1, en) * a;
		int l = (en - lim + 1 + n) % n;
		int r = en;
		need += pre[r] * b + (l != 0? suf[l] * b: 0);
		if (need <= t)
			return 1;
	}
	return 0;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read(), a = read(), b = read(), t = read();
	cin >> s;
	for (int i = n - 1; i >= 0; --i)
		suf[i] =  suf[i + 1] + (s[i] == 'w');
	pre[0] = (s[0] == 'w');
	for (int i = 1; i < n; ++i)
		pre[i] = pre[i - 1] + (s[i] == 'w');
	int bl = 0, br = n + 1;
	while (bl < br - 1) {
		int bm = bl + br >> 1;
		if (check(bm))
			bl = bm;
		else
			br = bm;
	}
	cout << bl << endl;
}