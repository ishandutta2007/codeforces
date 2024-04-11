// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 4e5 + 10;
int n, q, x;

struct node {
	vector<pll> pref, suff;
	ll ans = 0, l = 0, r = 0;
	node() {}

	node(int val, int ind) {
		pref.push_back({val, ind});
		suff.push_back({val, ind});
		if (val >= x) ans = 1;
		l = r = ind;
	}

	void wtf(node& a) {
		pref = a.pref;
		suff = a.suff;
		l = a.l;
		r = a.r;
		ans = a.ans;
	}

	node(node a, node b) {
		if (a.l == 0) {
			wtf(b);
			return;
		}

		if (b.l == 0) {
			wtf(a);
			return;
		}

		ans = a.ans + b.ans;
		
		int ind = b.pref.size() - 1;
		for (int i = 0; i < (int) a.suff.size(); i++) {	
			if ((b.pref.back().X | a.suff[i].X) < x) continue;
			while (ind && (b.pref[ind - 1].X | a.suff[i].X) >= x) ind--;
			int cnt_r = b.r - b.pref[ind].Y + 1, cnt_l = a.suff[i].Y;
			

			if (i < (int) a.suff.size() - 1) cnt_l -= a.suff[i + 1].Y;
			else cnt_l -= a.l - 1;
			ans += 1ll * cnt_l * cnt_r;
		}

	
		pref = a.pref;
		for (pll e : b.pref)
			if ((pref.back().X | e.X) != pref.back().X) 
				pref.push_back({pref.back().X | e.X, e.Y});	
		suff = b.suff;
		for (pll e : a.suff)
			if ((suff.back().X | e.X) != suff.back().X)
				suff.push_back({suff.back().X | e.X, e.Y});
		
		l = a.l;
		r = b.r;
	}
};

node sg[MAXN];
int A[MAXN];

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) sg[v] = node(A[l], l);
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = node(sg[v << 1], sg[v << 1 | 1]);
	}
}

void update(int ind, int val, int l = 1, int r = n, int v = 1) {
	if (l == r) sg[v] = node(val, ind);
	else {
		int mid = (l + r) >> 1;
		if (ind <= mid) update(ind, val, l, mid, v << 1);
		else update(ind, val, mid + 1, r, v << 1 | 1);
		sg[v] = node(sg[v << 1], sg[v << 1 | 1]);
	}
}

node query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	if (ql > r || qr < l) return node();
	if (ql <= l && qr >= r) return sg[v];
	
	int mid = (l + r) >> 1;
	return node(query(ql, qr, l, mid, v << 1),
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q >> x;
	for (int i = 1; i <= n; i++) cin >> A[i];
	build();

	while (q--) {
		int c, x, y;
		cin >> c >> x >> y;
		if (c == 1) update(x, y);
		else cout << query(x, y).ans << endl;
	}
	return 0;
}