// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;
typedef  pair<pll, pll> plll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;

vector<pair<plll, int>> v;
vector<int> L_l[MAXN], R_l[MAXN];
int k, q, MSK, ans_L[MAXN], ans_R[MAXN], ps_L[MAXN], ps_R[MAXN];

inline pll F(ll a) {
	return {(a >> k) & MSK, a & MSK};
}

inline pair<plll, int> g(int a, int b, int c, int d, int f) {
	return {{{a, b}, {c, d}}, f};
}

inline void calc(int b) {
	int mx = -1;
	for (int i = 0; i < MAXN; i++) {
		for (int e : L_l[i])
			mx = max(mx, e);
		
		if (i) ps_L[i] = ps_L[i - 1];
		if (mx >= i) {
			ans_L[i] ^= (1 << b);
			ps_L[i]++;
		}
	}

	mx = -1;
	for (int i = 0; i < MAXN; i++) {
		for (int e : R_l[i])
			mx = max(mx, e);
		
		if (i) ps_R[i] = ps_R[i - 1];
		if (mx >= i) {
			ans_R[i] ^= (1 << b);
			ps_R[i]++;
		}
	}
}

inline int cl(int l, int r) {
	int ans = ps_L[r];
	if (l) ans -= ps_L[l - 1];
	return ans;
}

inline int cr(int l, int r) {
	int ans = ps_R[r];
	if (l) ans -= ps_R[l - 1];
	return ans;
}

inline void majik(bool b) {
	if (!b) {
		cout << "impossible" << endl;
		exit(0);
	}
}

inline void wtf(int b) {
	for (int i = 0; i < MAXN; i++) {
		L_l[i].clear();
		R_l[i].clear();
		ps_L[i] = 0;
		ps_R[i] = 0;
	}

	for (auto e : v) {
		if (e.Y & (1 << b)) {
			L_l[e.X.X.X].push_back(e.X.X.Y);
			R_l[e.X.Y.X].push_back(e.X.Y.Y);
		}
	}

	calc(b);
	for (auto e : v) {
		pll l = e.X.X, r = e.X.Y;
		if ((e.Y & (1 << b)) == 0)
			majik(cl(l.X, l.Y) == 0 || cr(r.X, r.Y) == 0);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> k >> q;
	MSK = (1 << k) - 1;

	while (q--) {
		ll tl, tr, val;
		cin >> tl >> tr >> val;
		pll l = F(tl), r = F(tr);

		if (l.X == r.X) v.push_back(g(l.X, r.X, l.Y, r.Y, val));
		else {
			v.push_back(g(l.X, l.X, l.Y, MSK, val));
			v.push_back(g(r.X, r.X, 0, r.Y, val));
			if (l.X + 1 < r.X) v.push_back(g(l.X + 1, r.X - 1, 0, MSK, val));
		}
	}
/*
	for (auto e : v) {
		cerr << "! " << e.X.X.X << sep << e.X.X.Y << sep << e.X.Y.X << sep << e.X.Y.Y << sep << e.Y << endl;
	} */

	for (int i = 0; i < 16; i++)
		wtf(i);

	cout << "possible" << endl;
	for (int i = 0; i <= MSK; i++) cout << ans_R[i] << endl;
	for (int i = 0; i <= MSK; i++) cout << ans_L[i] << endl;
	return 0;
}