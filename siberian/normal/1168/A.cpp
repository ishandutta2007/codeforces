#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, m;
vector<int> a;
void read() {
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	auto b = a;
	sort(b.begin(), b.end());
	if (b == a) {
		cout << 0 << endl;
		exit(0);
	}
}

bool check(int x) {
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] + x < m) {
			if (a[i] + x < num)
				return false;
			num = max(num, a[i]);
		}
		else {
			if ((a[i] + x) % m >= num)
				continue;
			num = max(num, a[i]);
		}
	}
	return true;
}

int ans;
void run() {
	int l = 0, r = m;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	ans = r;
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