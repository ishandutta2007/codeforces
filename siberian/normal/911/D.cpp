#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}

bool ans;
vector<string> fans;
void run() {
	ans = false;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				ans ^= 1;
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		ans ^= ((r - l + 1) * (r - l) / 2) & 1;
		if (ans) {
			fans.push_back("odd");
		} else {
			fans.push_back("even");
		}
	}
}

void write() {
	for (auto i : fans) {
		cout << i << "\n";
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