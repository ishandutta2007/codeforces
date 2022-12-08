#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 100005;
int n, k, a[N], sum[N], b[N], len, mx, pre, cov[N];
vector<int> bin;

void qmax(int &x, int y) { x = max(x, y); }
void cover(int l, int r) { if(l <= r) cov[l]++, cov[r + 1]--; }
void doit() { for(int i = 1; i <= n; i++) cov[i] += cov[i - 1]; }

namespace BIT {
	int cnt[N], sum[N], mx[N];
	void clear() { memset(sum, 0, sizeof(sum)), memset(mx, 0, sizeof(mx)), memset(cnt, 0, sizeof(cnt)); }
	int lowbit(int x) { return x & (-x); }
	void addSum(int x, int v) { while(x) sum[x] += v, x -= lowbit(x); }
	void addCnt(int x, int v) { while(x) cnt[x] += v, x -= lowbit(x); }
	void addMax(int x, int v) { while(x) qmax(mx[x], v), x -= lowbit(x); }
	int askCnt(int x) { int r(0); while(x <= len) r += cnt[x], x += lowbit(x); return r; }
	int askSum(int x) { int r(0); while(x <= len) r += sum[x], x += lowbit(x); return r; }
	int askMax(int x) { int r(0); while(x <= len) qmax(r, mx[x]), x += lowbit(x); return r; }
}

namespace SGT {
	#define lc (u << 1)
	#define rc (u << 1 | 1)
	#define mid ((l + r) >> 1)
	int mn[N << 2], mx[N << 2];
	void build(int u, int l, int r) {
		if(l == r) return mn[u] = mx[u] = sum[l], void();
		build(lc, l, mid), build(rc, mid + 1, r);
		mn[u] = min(mn[lc], mn[rc]), mx[u] = max(mx[lc], mx[rc]);
	}
	
	int queryMax(int u, int l, int r, int a, int b) {
		if(a == l && r == b) return mx[u];
		if(b <= mid) return queryMax(lc, l, mid, a, b);
		else if(a > mid) return queryMax(rc, mid + 1, r, a, b);
		else return max(queryMax(lc, l, mid, a, mid), queryMax(rc, mid + 1, r, mid + 1, b));
	}
	
	int queryMin(int u, int l, int r, int a, int b) {
		if(a == l && r == b) return mn[u];
		if(b <= mid) return queryMin(lc, l, mid, a, b);
		else if(a > mid) return queryMin(rc, mid + 1, r, a, b);
		else return min(queryMin(lc, l, mid, a, mid), queryMin(rc, mid + 1, r, mid + 1, b));
	}
	#undef lc
	#undef rc
	#undef mid
}

pair<int, int> chk(int mid) {
	memset(cov, 0, sizeof(cov)), BIT::clear();
	pair<int, int> res = { 0, 0 };
	for(int i = n - 1; i >= 0; i--) {
		BIT::addCnt(sum[i + 1], 1), BIT::addSum(sum[i + 1], b[sum[i + 1]]), BIT::addMax(sum[i + 1], i + 1);
		int nxt = lower_bound(b + 1, b + 1 + len, b[sum[i]] - mid) - b;
		int nw = BIT::askCnt(nxt), lst = BIT::askMax(nxt);
		res.first += BIT::askSum(nxt) - b[sum[i]] * nw + mid * nw, res.second += nw;
		if(nw) cover(i + 1, lst);
	}
	doit(), bin.clear();
	for(int i = 1; i <= n; i++) if(!cov[i]) bin.push_back(i);
//	if(mid == -8) {
//		cout << res.first << " " << res.second << endl;
//		for(int i = 1; i <= n; i++) cout << cov[i] << " ";
//		cout << endl;
//	}
	if(!bin.size()) return res;
	res.second++, res.first += SGT::queryMax(1, 0, n, bin[bin.size() - 1], n) - SGT::queryMin(1, 0, n, 0, bin[0] - 1) + mid;
	for(int i = 0; i + 1 < bin.size(); i++) {
		int l = bin[i], r = bin[i + 1] - 1;
		int der = SGT::queryMax(1, 0, n, l, r) - SGT::queryMin(1, 0, n, l, r) + mid;
//		if(mid == -8) cout << l << " " << r << " " << der << endl;
		if(der >= 0) res.first += der, res.second++;
	}
	return res;
}

main() {
	n = get(), k = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++) b[i] = sum[i] = sum[i - 1] + a[i], pre = max(pre, sum[i]);
	SGT::build(1, 0, n);
	sort(b + 1, b + 1 + n + 1), len = unique(b + 1, b + 1 + n + 1) - b - 1;
	for(int i = 0; i <= n; i++) sum[i] = lower_bound(b + 1, b + 1 + len, sum[i]) - b;
	int l = -5e9, r = 5e9, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		int res = chk(mid).second;
		if(res >= k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	pair<int, int> res = chk(ans);
	cout << res.first - k * ans;
//	cout << ans << endl; 
	return 0;
}