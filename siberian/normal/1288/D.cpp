#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 3e5 + 10;
const int MAXM = 8;
int a[MAXN][MAXM];
int n, m;

void read() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
}

int mask[1 << MAXM];

int get_mask(int pos, int need) {
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (a[pos][i] >= need)
			ans |= (1 << i);
	}
	return ans;
}

bool check(int mid) {
	for (int i = 0; i < (1 << m); i++)
		mask[i] = -1;
	for (int i = 0; i < n; i++) {
		int fmask = get_mask(i, mid);
		if (fmask == ((1 << m) - 1)) return true;
		for (int s = fmask; s > 0; s = (fmask & (s - 1))) {
			mask[s] = i;
		}
	}
	for (int i = 0; i < (1 << m); i++) {
		if (mask[i] == -1) continue;
		int fmask = ((1 << m) - 1) ^ i;
		if (mask[fmask] != -1) {
			return true;
		}
	}
	return false;
}

int ans1, ans2;

void make_ans(int mid) {
	for (int i = 0; i < (1 << m); i++)
		mask[i] = -1;
	for (int i = 0; i < n; i++) {
		int fmask = get_mask(i, mid);
		if (fmask == (1 << m) - 1) {
			ans1 = i;
			ans2 = i;
			return;
		}
		for (int s = fmask; s > 0; s = (fmask & (s - 1))) {
			mask[s] = i;
		}
	}
	for (int i = 0; i < (1 << m); i++) {
		if (mask[i] == -1) continue;
		int fmask = ((1 << m) - 1) ^ i;
		if (mask[fmask] != -1) {
			ans1 = mask[i], ans2 = mask[fmask];
			return;
		}
	}
}

void run() {
	int l = 0, r = 1e9 + 10;
	while (l < r - 1) {
		//cout << l << " " << r << endl;
		int mid = (l + r) / 2;
		if (check(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	//cout << "l = " << l << endl;
	make_ans(l);
}

void write() {
	cout << ans1 + 1 << " " << ans2 + 1 << endl;
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