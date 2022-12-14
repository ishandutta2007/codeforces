//In the name of God
// ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }



const int N = 1e5 + 5;
const int lgN = 21;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e9 + 9;

int n, mark[N], par[N], h, t, q[N], a[N], b[N], c[N], d[N];
pii p[N];
int pt[lgN][N];
pii seg[lgN][N];

int read() { int x; cin >> x; return x; }

void build(int d = 0, int s = 0, int e = n) {
	if (s + 1 == e) {
		seg[d][s] = {b[p[s].second], p[s].second};
		return;
	}
	int m = (s + e) >> 1;
	build(d + 1, s, m);
	build(d + 1, m, e);
	merge(seg[d + 1] + s, seg[d + 1] + m, seg[d + 1] + m, seg[d + 1] + e, seg[d] + s);
}

void query(int i, int j, int x, int d = 0, int s = 0, int e = n) {
	if (i >= e || s >= j)
		return;
	if (i <= s && e <= j) {
		if (pt[d][s] == 0)
			pt[d][s] = s;
		while (pt[d][s] != e && seg[d][pt[d][s]].first <= ::d[x]) {
			int id = seg[d][pt[d][s]++].second;
			if (!mark[id])
				q[t++] = id, mark[id] = 1, par[id] = x;
		}
		return;
	}
	int m = (s + e) >> 1;
	query(i, j, x, d + 1, s, m);
	query(i, j, x, d + 1, m, e);
}

void show(int x, int cnt = 0) {
	if (x == -1) {
		cout << cnt << endl;
		return;
	}
	show(par[x], cnt + 1);
	cout << x + 1 << ' ';
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read();
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i], p[i] = {a[i], i};
	sort(p, p + n);
	build();
	for (int i = 0; i < n; i++)
		if (a[i] == 0 && b[i] == 0)
			mark[i] = 1, q[t++] = i, par[i] = -1;
	while (h != t) {
		int x = q[h++];
		query(0, upper_bound(p, p + n, make_pair(c[x], oo)) - p, x);
	}
	if (!mark[n - 1]) {
		cout << -1;
		return 0;	
	}
	show(n - 1);
}