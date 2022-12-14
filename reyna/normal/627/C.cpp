//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define int long long
const int N = 2e5 + 5, S = N * 70;

int read() { int x; cin >> x; return x; }
int d, gas, n;

//void build(int v = 1, int b = 0, int e = d) {
//	if (b + 1 == e) {
//		cnt[v] = 1;
//		return;
//	}
//	int m = b + e >> 1, l = v << 1, r = l | 1;
//	build(l, b, m);
//	build(r, m, e);
//	cnt[v] = cnt[l] + cnt[r];
//}

//void push(int v) {
//	if (!ch[v]) {
//		return;
//	}
//	int l = L[v], r = R[v];
//	cnt[l] = cnt[r] = 0;
//	ch[l] = ch[r] = 1;
//}
//
//void extend(int v, int b, int e) {
//	if (L[v] == -1) {
//		L[v] = sz++, R[v] = sz++;
//		int mid = b + e >> 1;
//		cnt[L[v]] = mid - b;
//		cnt[R[v]] = e - mid;
//	}
//}
//
//int query(int i, int j, int v = 0, int b = 0, int e = d) {
//	if (i >= e || b >= j)
//		return 0;
//	if (i <= b && e <= j) {
//		return cnt[v];
//	}
//	extend(v, b, e);
//	int m = b + e >> 1, l = L[v], r = R[v];
//	push(v);
//	return query(i, j, l, b, m) + query(i, j, r, m, e);
//}
int par[N];
int find(int v) { return par[v] == v? v: par[v] = find(par[v]); }
void unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (u > v)
		swap(u, v);
	par[u] = v;
}

//void update(int i, int j, int v = 0, int b = 0, int e = d) {
//	if (i >= e || b >= j)
//		return;
//	if (i <= b && e <= j) {
//		cnt[v] = 0;
//		ch[v] = 1;
//		return;
//	}
//	extend(v, b, e);
//	int m = b + e >> 1, l = L[v], r = R[v];
//	push(v);
//	update(i, j, l, b, m);
//	update(i, j, r, m, e);
//	cnt[v] = cnt[l] + cnt[r];
//}
pair<int, int> s[N];
int val[N], pp[N];


int32_t main() {
//	memset(L, -1, sizeof L);
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> d >> gas >> n;
	rep(i, n) {
		cin >> s[i].second >> s[i].first;
		pp[i] = s[i].second;
	}
	pp[n] = 0;
	s[n++] = {0, 0};
	pp[n] = d;
	s[n++] = {0, d};
	sort(s, s + n);
	sort(pp, pp + n);
		
	rep(i, n) {
		par[i] = i;
	}
	par[n] = n;
//	build();
	int res = 0;
	rep(i, n) {
		int pos = s[i].second, cost = s[i].first;
		int cur = find(lower_bound(pp, pp + n, pos) - pp);
		while (cur < n - 1 && pp[cur] + val[cur] < pos + gas) {
			int add = min(pp[cur + 1] - pp[cur] - val[cur], pos + gas - pp[cur] - val[cur]);
			val[cur] += add;
			res += add * cost;
			if (val[cur] == pp[cur + 1] - pp[cur])
				unite(cur, cur + 1);
			cur = find(cur);
		}
//		res += query(pos, pos + gas) * cost;
//		update(pos, pos + gas);
	}
	rep(i, n) {
		if (pp[i] - pp[i - 1] > gas) {
			cout << -1;
			return 0;
		}
	}
//	if (query(0, d) != 0) {
//		cout << -1;
//		return 0;
//	}
	cout << res;
}