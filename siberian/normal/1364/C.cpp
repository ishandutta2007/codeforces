#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
}

void no() {
	cout << -1 << endl;
	exit(0);
}

vector<int> ans;

void run() {
	int now = 0;
	ans.resize(n, 1e6);
	set<pair<int, int>> fans;
	for (int i = 0; i < n; i++) {
		if (now > a[i]) {
			no();
		} else if (now == a[i]) {
			fans.insert({a[i], i});
		} else {
			now++;
			ans[i] = now - 1;
			while (now < a[i]) {
				auto it = fans.upper_bound(make_pair(now, n));
				if (it == fans.begin()) no();
				it--;
				now++;
				ans[it->second] = now - 1;
				fans.erase(it);
			}
		}
	}
}

void write() {
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;
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