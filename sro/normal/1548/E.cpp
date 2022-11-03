#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

const int maxn = 1 << 18;

struct Fenwick {
	int dt[maxn];
	void inline add(int a, int x) {
		while (a < maxn) {
			dt[a] += x;
			a += a & -a;
		}
	}
	int inline sum(int a) {
		if (a < 0) return 0;
		int res = 0;
		while (a) {
			res += dt[a];
			a -= a & -a;
		}
		return res;
	}
} t1, t2;

struct ZkwSeg {
	int dt[maxn << 1];
	void inline init() { memset(dt, 0, sizeof(dt)); }
	void inline add(int a, int x) {
		dt[a += maxn] += x;
		while (a >>= 1) dt[a] = max(dt[a << 1], dt[a << 1 | 1]);
	}
	int inline get(int l, int r) {
		int res = 0;
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = max(res, dt[l++]);
			if (r & 1) res = max(res, dt[--r]);
		}
		return res;
	}
} seg;

int N, M, X;
int a[maxn], b[maxn];
int mxa[maxn], mxb[maxn];
vector<pair<int, int> > stk;

void inline getmx(int a[], int mxa[], int N) {
	seg.init();
	repi(i, N) seg.add(i, a[i]);
	repi(i, N) mxa[i] = 0x3f3f3f3f;
	stk.clear();
	for (int i = N; i; --i) {
		while (SZ(stk) && stk.back().second >= a[i]) {
			int id = stk.back().first;
			mxa[id] = seg.get(i, id);
			stk.pop_back();
		}
		stk.emplace_back(i, a[i]);
	}
	stk.clear();
	repi(i, N) {
		while (SZ(stk) && stk.back().second > a[i]) {
			int id = stk.back().first;
			mxa[id] = min(mxa[id], seg.get(id, i));
			stk.pop_back();
		}
		stk.emplace_back(i, a[i]);
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &X);
	repi(i, N) scanf("%d", a + i);
	repi(i, M) scanf("%d", b + i);
	getmx(a, mxa, N);
	getmx(b, mxb, M);
	vector<tuple<int, int, int> > pos;
	repi(i, N) pos.emplace_back(a[i] - mxa[i], a[i], 0);
	repi(i, M) pos.emplace_back(b[i] - mxb[i], b[i], 1);
	sort(pos.begin(), pos.end());
	ll ans = 0;
	for (auto &it : pos) {
		int mode = get<2>(it), val = get<1>(it);
		int mx = val - get<0>(it);
		if (!mode) {
			ans += t2.sum(X - val) - t2.sum(X - mx);
			t1.add(val, 1);
		}
		else {
			ans += t1.sum(X - val) - t1.sum(X - mx);
			t2.add(val, 1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}