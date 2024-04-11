#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
vector <int> a;

bool check(int l, int r) {
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < a[i - 1]) return false;
	}
	return true;
}

void read() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 1;
	for (int i = 0; pow(2, i) <= n; i++) {
		int x = pow(2, i);
		//cout << x << endl;
		for (int j = 0; j < n; j+=x) {
			if (check(j, j + x - 1)) ans = x;
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