//In the name of God
// (c) Silver soul 49
// What i'll engrave in this place is my soul!!!

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for(int i = (s); i < (e); i++)
#define x first
#define y second
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }



/*******************************************************************************************************/

const int maxD = 149;
const int maxN = 15e4 + 49;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e9 + 49;

int dp[maxD][1049];
int ql[maxN], qr[maxN], xv[maxN], xw[maxN], n, k, cnt3 = 0, sz = 0, ans[maxN], pp = 3e4 + 49, phash = 1e7 + 19, qhash = 1e9 + 7, pw[maxN];
vector<pii> t[maxN];

void push(int i, int j, pii x, int v = 1, int b = 0, int e = pp) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		t[v].push_back(x);
		return;	
	}
	int mid = (b + e) >> 1, l = v << 1, r = l | 1;
	push(i, j, x, l, b, mid), push(i, j, x, r, mid, e);
}

void dfs(int v = 1, int b = 0, int e = pp, int d = 1) {
	memcpy(dp[d], dp[d - 1], sizeof (dp[d - 1]));
	for (pii x : t[v]) {
		int vx = x.first, wx = x.second;
		for (int i = k; i >= wx; --i)
			smax(dp[d][i], dp[d][i - wx] + vx);
	}
	if (b + 1 == e) {
		int res = 0, p = 0;
		for (int i = 1; i <= k; i++) {
			smax(p, dp[d][i]);
			if (b < cnt3) {
				res = (res + p * 1LL * pw[i - 1]) % qhash;
			}
		}
		ans[b] = res;
		return;
	}
	int mid = (b + e) >> 1, l = v << 1, r = l | 1;
	dfs(l, b, mid, d + 1);
	dfs(r, mid, e, d + 1);
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k; sz = n;
	for (int i = 0; i < maxN; i++)
		pw[i] = (i? pw[i - 1] * 1LL * phash % qhash: 1);
	for (int i = 1; i < 1049; i++)
		dp[0][i] = -oo;
	for (int i = 0; i < n; i++) {
		cin >> xv[i] >> xw[i];
		ql[i] = 0, qr[i] = pp;
	}
	int q; cin >> q;
	for (int _ = 0; _ < q; _++) {
		int c; cin >> c;
		if (c == 1) {
			cin >> xv[sz] >> xw[sz];
			ql[sz] = cnt3;
			qr[sz++] = pp;
		} else if (c == 2) {
			int id; cin >> id; id--;
			qr[id] = cnt3;
		} else {
			cnt3++;	
		}
	}
	for (int i = 0; i < sz; i++) {
		int l = ql[i], r = qr[i];
		push(l, r, {xv[i], xw[i]});	
	}
	dfs(1);
	for (int i = 0; i < cnt3; i++)
		cout << ans[i] << '\n';
}