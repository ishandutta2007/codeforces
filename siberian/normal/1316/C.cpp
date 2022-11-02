#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void read() {
	int n, m, p;
	int ans = 0;
	cin >> n >> m >> p;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % p != 0 && !flag) {
			ans += i;
			flag = true;
		} 
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x % p != 0) {
			ans += i;
			break;
		}
	}
	cout << ans << endl;
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