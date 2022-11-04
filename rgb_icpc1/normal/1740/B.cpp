#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define endl '\n'
using LL = long long;
using PII = pair<LL, LL>;
using VI = vector<LL>;
using VPII = vector <PII>;
const LL MN = 400005;
LL a[MN];
LL b[MN];
LL v[MN];
LL nn;

void init (LL n) {
	nn = n;
	fill_n(v, n + 1, 0);
}

void add (LL u, LL d) {
	for (; u <= nn; u += u & -u) v[u] += d;
}

LL get (LL u) {
	LL rlt = 0;
	for (; u; u -= u & -u) rlt += v[u];
	return rlt;
}

LL X[MN], XN;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	LL Tc; cin >> Tc;
	while (Tc --) {
		LL n; cin >> n;
		XN = 0;
		for (LL i = 0; i < n; i ++) cin >> a[i] >> b[i], X[XN ++] = a[i], X[XN ++] = b[i];
		sort (X, X + XN);
		XN = unique(X, X + XN) - X;
		init (XN);
		LL val = 0;
		for (LL i = 0; i < n; i ++) {
			val = max (val, min(a[i], b[i]));
		}
		LL rlt1 = 0;
		for (LL i = 0; i < n;i ++) rlt1 += a[i] + b[i];
//		cout << rlt1 << ' ' << val << endl;
		for (LL i = 0; i < n; i ++) {
			if (a[i] > b[i]) swap(a[i], b[i]);
			LL ida = lower_bound(X, X + XN, a[i]) - X + 1;
			LL idb = lower_bound(X, X + XN, b[i]) - X + 1;
			add(ida, a[i]);
			add(idb, b[i] - a[i]);
		}
		LL rlt = LLONG_MAX;
		for (LL i = 0; i < XN; i ++) {
			if (X[i] < val) continue;
			LL tot = 2 * (rlt1 - get(i + 1)) + 2 * X[i];
			rlt = min (rlt, tot);
		}
		cout << rlt << endl;
	}
	return 0;
}