#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, s;

void read() {
	cin >> n >> s;
}

vector<int> ans;

void run() {
	for (int i = 0; i < n - 1; i++)
		ans.push_back(1);
	ans.push_back(s - (n - 1));
	if ((s + 1) / 2 >= ans.back() || s / 2 <= n - 1) {
		cout << "NO\n";
		exit(0);
	}
}

void write() {
	cout << "YES\n";
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
	cout << (s + 1) / 2 << endl;
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