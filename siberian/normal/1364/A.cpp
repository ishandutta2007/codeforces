#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void read() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (auto &i : a) cin >> i;
		int have = -1;
		int now = 0;
		int ans = -1;
		for (int i = 0; i < n; i++) {
			now += a[i];
			now %= x;
			if (now != 0) {
				chkmax(ans, i + 1);
			}
			if (have != -1) {
				chkmax(ans, i - have);
			}
			if (have == -1 && now != 0) {
				have = i;
			}
		}
		cout << ans << endl;
	}
}

void run() {

}

void write() {

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