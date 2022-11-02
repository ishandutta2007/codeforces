#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, a, b;

void read() {
	cin >> n >> a >> b;
}

int ans;

bool check() {
	if (a == 0) return b / ans > 0;
	if (b == 0) return a / ans > 0;
	return a >= ans && b >= ans && a / ans + b / ans >= n;
}

void run() {
	ans = 1;
	while (check()) {
		ans++;
	}
	ans--;
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