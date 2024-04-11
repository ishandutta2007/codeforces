#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct fenvik{
	vector<int> tree;
	int n;
	fenvik() {}
	fenvik(int sz) {
		n = sz;
		tree.assign(n, 0);
	}

	void upd(int pos, int val) {
		for (; pos < n; pos |= pos + 1)
		tree[pos] += val;
	}

	int get(int r) {
		int ans = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) {
			ans += tree[r];
		}
		return ans;
	}
};

int n, q;
fenvik a;

void read() {
	cin >> n >> q;
	q = n + q;
	a = fenvik(n);	
}

void run() {
	while (q--) {
		int x;
		cin >> x;
		if (x > 0) {
			x--;
			a.upd(x, 1);
		} else {
			x = abs(x);
			int l = -1, r = n - 1;
			while (l < r - 1) {
				int mid = (l + r) / 2;
				if (a.get(mid) >= x) {
					r = mid;
				} else {
					l = mid;
				}
			}
			//cout << "r = " << r << endl;
			a.upd(r, -1);
		}
	}
}

void write() {
	int l = -1, r = n;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (a.get(mid) >= 1) {
			r = mid;
		} else {
			l = mid;
		}
	}
	if (r == n) r = 0;
	else r = r + 1;
	cout << r << endl;
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