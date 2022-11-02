#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,mmx,abm")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct event{
	int x, type, data;
	event() {}
	event(int _x, int _type, int _data) {
		x = _x, type = _type, data = _data;
	}
};

bool operator<(const event & a, const event & b) {
	return tie(a.x, a.type) < tie(b.x, b.type);
}

const int MAXLOG = 17;
const int MAXN = 1e5 + 10;
const int Bloks = 30;
const int LONG_Bloks = 1200;
const int INF = 2e9 + 10;
int n, w, q;
int a[MAXN];
int sp_mn[MAXN][MAXLOG], sp_mx[MAXN][MAXLOG];
int lg[MAXN];

void build_sparce() {
	lg[0] = lg[1] = 0;
	for (int i = 2; i < n; i++)
		lg[i] = lg[i / 2] + 1;

	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXLOG; j++)
			sp_mn[i][j] = INF, sp_mx[i][j] = -INF;

	for (int i = 0; i < n; i++) {
		sp_mn[i][0] = a[i];
		sp_mx[i][0] = a[i];
	}

	for (int l = 1; l < MAXLOG; l++) {
		for (int i = 0; i + (1 << l) <= n; i++) {
			sp_mn[i][l] = min(sp_mn[i][l - 1], sp_mn[i + (1 << (l - 1))][l - 1]);
			sp_mx[i][l] = max(sp_mx[i][l - 1], sp_mx[i + (1 << (l - 1))][l - 1]);
		}
	}
}

int get_mn(int l, int r) {
	return min(sp_mn[l][lg[r - l]], sp_mn[r - (1 << lg[r - l]) + 1][lg[r - l]]);
}

int get_mx(int l, int r) {
	return max(sp_mx[l][lg[r - l]], sp_mx[r - (1 << lg[r - l]) + 1][lg[r - l]]);
}

void read() {
	cin >> n >> w >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

vector<event> have;
int ptr[MAXN];
int val_mn[MAXN], val_mx[MAXN];
int jumps[MAXN], link[MAXN];

void precalc() {
	for (int i = 0; i < n; i++) {
		ptr[i] = i + 1;
		val_mn[i] = min(a[i], a[i + 1]);
		val_mx[i] = max(a[i], a[i + 1]);
		int mn = a[i], mx = a[i];
		for (int j = i + 1; j <= min(i + Bloks, n - 1); j++) {
			chkmin(mn, a[j]);
			chkmax(mx, a[j]);
			have.push_back({mx - mn, 0, i});
		}
	}
	for (int i = 0; i < q; i++) {
		int k;
		cin >> k;
		have.push_back({w - k, 1, i});
	}
	sort(all(have));
}

int ans[MAXN];

// type == 0 -> , type == 1 -> 

void upd(int pos) {
	ptr[pos]++;
	chkmin(val_mn[pos], a[ptr[pos]]);
	chkmax(val_mx[pos], a[ptr[pos]]);
	for (int i = pos; i >= max(0, pos - Bloks + 1); i--) {
		int r = min(i + Bloks, n);
		link[i] = i;
		jumps[i] = 0;
		while (ptr[link[i]] < r) {
			jumps[i]++;
			link[i] = ptr[link[i]];
		}
	}
}

int find_nxt(int pos, int k) {
	while (ptr[pos] < n && ptr[pos] < pos + LONG_Bloks && val_mx[pos] - val_mn[pos] <= k) {
		ptr[pos]++;
		chkmin(val_mn[pos], a[ptr[pos]]);
		chkmax(val_mx[pos], a[ptr[pos]]);
	}

	if (ptr[pos] < pos + LONG_Bloks) {
		return ptr[pos];
	}

	int l = pos, r = n;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (get_mx(pos, mid) - get_mn(pos, mid) <= k)
			l = mid;
		else
			r = mid;		
	}
	return r;
}

int solve(int k) {
	int pos = 0;
	int ans = 0;
	while (pos < n) {
		ans += jumps[pos];
		pos = link[pos];
		if (pos < n && link[pos] == pos) {
			ans++;
			pos = find_nxt(pos, k);
		}
	}
	return ans;
}

void solve() {
	for (int i = 0; i < n; i++) {
		link[i] = min(i + Bloks, n);
		jumps[i] = link[i] - i;
	}
	for (auto el : have) {
		if (el.type == 0) {
			upd(el.data);
		} else {
			ans[el.data] = solve(el.x);
		}
	}
}

void run() {
	build_sparce();
	precalc();
	solve();
}

void write() {
	for (int i = 0; i < q; i++) {
		cout << ans[i] - 1 << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}