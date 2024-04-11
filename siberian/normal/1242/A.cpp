#include <bits/stdc++.h>

using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;

void read() {
	cin >> n;
}

int ans;

void run() {
	vector<int> num;
	int x = n;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			num.push_back(i);
			n /= i;
		}
	}
	if (n != 1 && n != x) {
		num.push_back(n);
	}
	sort(all(num));
	num.resize(unique(all(num)) - num.begin());
	if (num.empty()) {
		ans = x;
		return;
	}
	if (num.size() == 1) {
		ans = num[0];
		return;
	}
	ans = 1;
	return;
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