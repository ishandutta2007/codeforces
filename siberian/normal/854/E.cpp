#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops,inline")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define find find228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2e5 + 10;
int n, k;
int tree[MAXN];

int get(int r) {
	int ans = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		ans += tree[r];
	return ans;
}

int get(int l, int r) {
	return get(r) - get(l - 1);
}

void upd(int pos, int val) {
	for (; pos <= n; pos |= pos + 1)
		tree[pos] += val;
}

int a[MAXN];

struct event{
	int x, l, r, ind, id;
	event() {}
	event(int _x, int _l, int _r, int _ind) {
		x = _x, l = _l, r = _r, ind = _ind;
	}
};

bool operator<(const event & a, const event & b) {
	return a.x < b.x;
}

const int MAXQ = 2e5 * 6;
event q[MAXQ];
int topQ = 0;
int Qans[MAXQ];
int l[MAXN], r[MAXN], d[MAXN], u[MAXN];

void build_query() {
	for (int i = 0; i < k; i++) {
		cin >> l[i] >> d[i] >> r[i] >> u[i];
		q[topQ] = {l[i] - 1, 1, d[i] - 1, topQ}; topQ++;
		q[topQ] = {l[i] - 1, d[i], u[i], topQ}; topQ++;
		q[topQ] = {l[i] - 1, u[i] + 1, n, topQ}; topQ++;

		q[topQ] = {r[i], 1, d[i] - 1, topQ}; topQ++;
		q[topQ] = {r[i], d[i], u[i], topQ}; topQ++;
		q[topQ] = {r[i], u[i] + 1, n, topQ}; topQ++;
	}
	sort(q, q + topQ);
}

void build_Qans() {
	int posQ = 0;
	for (int i = 0; i <= n; i++) tree[i] = 0;
	for (int i = 0; i <= n; i++) {
		if (i > 0)
		upd(a[i], 1);
		while (posQ < topQ && q[posQ].x == i) {
			Qans[q[posQ].ind] = get(q[posQ].l, q[posQ].r);
			posQ++;
		}
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	build_query();
	build_Qans();

	for (int i = 0; i < k; i++) {
		int s1 = Qans[i * 6];
		int s2 = Qans[i * 6 + 1];
		int s3 = Qans[i * 6 + 2];
		int s4 = Qans[i * 6 + 3];
		int s5 = Qans[i * 6 + 4];
		int s6 = Qans[i * 6 + 5];
		int s7 = get(1, d[i] - 1);
		int s8 = get(d[i], u[i]);
		int s9 = get(u[i] + 1, n);
		s9 -= s6;
		s8 -= s5;
		s7 -= s4;
		s6 -= s3;
		s5 -= s2;
		s4 -= s1;
	
		ll ans = 0;
		ans += (ll)s1 * (s5 + s6 + s8 + s9);
		ans += (ll)s2 * (s4 + s5 + s6 + s7 + s8 + s9);
		ans += (ll)s3 * (s4 + s5 + s7 + s8);
		ans += (ll)s4 * (s5 + s6 + s8 + s9);
		ans += (ll)s5 * (s6 + s7 + s8 + s9);
		ans += (ll)s6 * (s7 + s8);  
		ans += (ll)s5 * (s5 - 1) / 2;
		cout << ans << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}