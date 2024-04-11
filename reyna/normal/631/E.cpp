//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll, ll> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define int long long
const int N = 1e6 + 6;

int read() { int x; cin >> x; return x; }

ll h, t, a[N];
pair<ll, ll> s[N];
ll add = 0;

ll when(pii x, pii y) {
	if (x.first > y.first)
		swap(x, y);
	return (y.first - x.first + x.second - y.second - 1) / (x.second - y.second);
}

ll solve(int n, int f = 0) {
	if (f)
		rep(i, n)
			a[i] *= -1;
	ll res = 0;
	h = 0, t = 0, add = 0;
	for (int i = n - 1; i >= 0; --i) {
		add += -a[i + 1];
		pii cur = {-add, i};
		bool flag = 1;
		while (t - h > 0) {
			ll arz = s[t - 1].first, shib = s[t - 1].second;
			if (arz >= cur.first && shib >= cur.second) {
				flag = 0;
				break;
			}
			if ((arz <= cur.first && shib <= cur.second) || (t - h > 1 && when(s[t - 1], s[t - 2]) <= when(s[t - 1], cur))) {
				t--;
				continue;
			}
			break;
		}
		if (flag)
			s[t++] = cur;
		int bl = -2, br = t - 1;
		while (bl < br - 1) {
			int bm = bl + br >> 1;
			ll x;
			if (bm < 0)
				x = 1e18;
			else if (bm == t - 1)
				x = -1e18;
			else
				x = when(s[bm], s[bm + 1]);	
			if (x <= a[i])
				br = bm;
			else
				bl = bm;
		}
//		br++;
//		if (t > 1)
//			cout << when(s[0], s[1]) << endl;
//		cout << br << ' ' << s[br].first << ' ' << s[br].second << ' ' << add << ' ' << t << endl;
		res = max(res, a[i] * (s[br].second - i) + s[br].first + add);
		
	}
	return res;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read();
	ll sum = 0;
	rep(i, n)
		a[i] = read(), sum += a[i] * (i + 1);
	ll res = solve(n);
	reverse(a, a + n);
	res = max(res, solve(n, 1));
	cout << res + sum << endl;
}