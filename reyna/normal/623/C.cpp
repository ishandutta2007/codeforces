// In the name of God

/*
	........
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
inline int read() { int32_t x; scanf("%d", &x); return x; }

const int N = 1e5 + 5;

int x[N], y[N], n, smn[N], smx[N], pmn[N], pmx[N];
pair<int, int> p[N];

int getst(int l, int r) { return min(smn[l], pmn[r]); }
int geted(int l, int r) { return max(smx[l], pmx[r]); }

ll sqr(ll x) { return x * x; }

bool solve(ll d) {
	int ed = 0;
//	for (int i = 0; i < n; ++i)
//		st.insert({p[i].second, i});
	smn[0] = pmn[n] = 0;
	smx[0] = pmx[n] = 0;
	for (int i = 1; i < n; ++i)
		smn[i] = min(smn[i - 1], p[i - 1].second), smx[i] = max(smx[i - 1], p[i - 1].second);
	
	for (int i = n - 1; i >= 0; --i)
		pmn[i] = min(pmn[i + 1], p[i].second), pmx[i] = max(pmx[i + 1], p[i].second);
		
	for (int i = 0; i < n; ++i) {
		while (ed < n && sqr(p[i].first - p[ed].first) <= d && abs(p[i].first) >= abs(p[ed].first))
			ed++;
		while (ed > i && abs(p[i].first) < abs(p[ed - 1].first))
			ed--;
		int mxval = ed - i != n? max(abs(getst(i, ed)), abs(geted(i, ed))): 0;
		if (sqr(mxval) + sqr(p[i].first) <= d && (ed - i == n || sqr(getst(i, ed) - geted(i, ed)) <= d))
			return 1;
//		st.insert({p[i].second, i});
	}
	return 0;

}

bool all(ll d) {
	int mxx = -1e9, mxy = -1e9, mnx = 1e9, mny = 1e9;
	for (int i = 0; i < n; ++i) {
		mxx = max(mxx, x[i]);
		mxy = max(mxy, y[i]);
		mnx = min(mnx, x[i]);
		mny = min(mny, y[i]);
	}
	if (sqr(mxx - mnx) <= d) return 1;
	if (sqr(mxy - mny) <= d) return 1;
	return 0;
}

bool check(ll d) {
	int res = 0;
	if (all(d)) return 1;
	res |= solve(d);
	if (!res) {
		reverse(p, p + n);
		res |= solve(d);
		reverse(p, p + n);
	}
	return res;
}

int main() {
	n = read();
	for (int i = 0; i < n; ++i) {
		x[i] = read();
		y[i] = read();
		p[i] = {x[i], y[i]};
	}
	sort(p, p + n);
	long long bl = -1, br = 4e16 + 1;
	while (bl < br - 1) {
		long long bm = bl + br >> 1;
		if (check(bm))
			br = bm;
		else
			bl = bm;
	} 
	cout << br << endl;
	
}