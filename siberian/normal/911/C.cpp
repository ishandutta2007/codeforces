#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

vector<int> a;

void read() {
	a.resize(3);
	for (auto &i : a) cin >> i;
	sort(all(a));
}

bool ans;

void run() {
	ans = false;
	if (a[0] == 1) ans = true;
	if (a[0] == 2 && a[1] == 2) ans = true;
	if (a[0] == 2 && a[1] == 4 && a[2] == 4) ans = true;
	if (a[0] == 3 && a[1] == 3 && a[2] == 3) ans = true;
}

void write() {
	if (ans) cout << "YES\n";
	else cout << "NO\n";
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