//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 4e5 + 5;

int read() { int x; cin >> x; return x; }

int a[N], dpl[N], dpr[N], lis[N], p, pos[N], cnt[N], pl[N];
vector<int> query[N], rgt[N], lft[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), q = read();
	rep(i, n)
		a[i] = read(), query[i].push_back(a[i]);
	rep(i, q) {
		pos[i] = read() - 1;
		int x = read();
		pl[i] = (int) query[pos[i]].size();
		query[pos[i]].push_back(x);
	}
	memset(lis, 63, sizeof lis);
	rep(i, n) {
		rep(j, (int) query[i].size()) {
			int bl = -1, br = p, x = query[i][j];
			while (bl < br - 1) {
				int bm = bl + br >> 1;
				if (lis[bm] >= x)
					br = bm;
				else
					bl = bm;
			}
			lft[i].push_back(br);
		}
		dpl[i] = lft[i][0];
		lis[dpl[i]] = a[i];
		if (dpl[i] == p)
			p++;
	}
	p = 0;
	memset(lis, -63, sizeof lis);
	for (int i = n - 1; i >= 0; --i) {
		rep(j, (int) query[i].size()) {
			int bl = -1, br = p, x = query[i][j];
			while (bl < br - 1) {
				int bm = bl + br >> 1;
				if (lis[bm] <= x)
					br = bm;
				else
					bl = bm;
			}
			rgt[i].push_back(br);
		}
		dpr[i] = rgt[i][0];
		lis[dpr[i]] = a[i];
		if (dpr[i] == p)
			p++;
	}
	int mx = 0;
	rep(i, n)
		smax(mx, dpl[i] + dpr[i] + 1);
	rep(i, n)
		if (mx == dpl[i] + dpr[i] + 1)
			cnt[dpl[i]]++;
	rep(j, q) {
		p = pos[j];
		int ans = mx;
		if (dpl[p] + dpr[p] + 1 == mx && cnt[dpl[p]] == 1)
			ans--;
		ans = max(ans, lft[p][pl[j]] + rgt[p][pl[j]] + 1);
		cout << ans << '\n';
	}
	
}