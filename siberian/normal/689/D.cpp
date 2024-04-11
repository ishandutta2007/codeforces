#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a, b;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	b.resize(n);
	for (auto &i : b)
		cin >> i;
}

const int MAXN = 2e5 + 10, MAXLOG = 19;

int logs[MAXN];
int sparce_a[MAXN][MAXLOG], sparce_b[MAXN][MAXLOG];

void build() {
	for (int i = 2; i < MAXN; i++)
		logs[i] = logs[i / 2] + 1;

	for (int i = 0; i < n; i++)
		sparce_a[i][0] = a[i], sparce_b[i][0] = b[i];
	
	for (int l = 1; l < MAXLOG; l++) {
		for (int i = 0; i + (1 << l) <= n; i++) {
			sparce_a[i][l] = max(sparce_a[i][l - 1], sparce_a[i + (1 << (l - 1))][l - 1]);
			sparce_b[i][l] = min(sparce_b[i][l - 1], sparce_b[i + (1 << (l - 1))][l - 1]);
		}
	}
}

int get_a(int l, int r) {
	int k = logs[r - l];
	return max(sparce_a[l][k], sparce_a[r - (1 << k)][k]);
}

int get_b(int l, int r) {
	int k = logs[r - l];
	return min(sparce_b[l][k], sparce_b[r - (1 << k)][k]);
}

int get_l(int pos) {
	int l = pos, r = n + 1;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (get_a(pos, mid) < get_b(pos, mid))
			l = mid;
		else
			r = mid;
	}
	return r;
}

int get_r(int pos) {
	int l = pos, r = n + 1;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (get_a(pos, mid) <= get_b(pos, mid))
			l = mid;
		else
			r = mid;
	}
	return r;
}

int solve(int pos) {
	int l = get_l(pos);
	int r = get_r(pos);
	//cout << "l = " << l << " r = " << r << endl;
	return r - l;
}

int ans;

void run() {
	build();
	ans = 0;
	for (int i = 0; i < n; i++) {
		ans += solve(i);
	}
}

void write() {
	cout << ans << endl;
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