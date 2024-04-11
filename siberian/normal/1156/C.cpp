#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, z;
vector <int> a;
void read() {
	cin >> n >> z;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
}

bool check(int x) {
	for (int i = n - x; i < n; i++) {
		if (a[i] - a[i - n + x] < z)
			return false;
	}
	return true;
}

int ans;
void run() {
	ans = 0;
	int l = 0, r = n / 2 + 1;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(mid)) 
			l = mid;
		else
			r = mid;
	} 
	ans = l;
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