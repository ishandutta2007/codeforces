#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
int n, m;
vector<int> a;
void read() {
	cin >> n >> m;
	a.resize(m);
	for (auto &i : a)
		cin >> i;
}

void no() {
	cout << -1 << endl;
	exit(0);
}

vector<int> ans;

void run() {
	int sum = 0;
	for (auto i : a)
		sum += i;
	if (sum < n) no();
	int now = 1;
	for (auto i : a) {
		ans.push_back(now);
		if (now + i - 1 > n) no();
		sum -= i;
		now = min(sum, n - now);
		now = n + 1 - now;
	}
}

void write() {
	for (auto i : ans)
		cout << i << " ";
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