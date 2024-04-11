#include <bits/stdc++.h>

using namespace std;
#define int long long

void read() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	while (n) {
		if (n % k == 0) {
			n /= k;
			ans++;
		}
		else {
			ans += n % k;
			n -= n % k;
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
	int t;
	cin >> t;
	while (t--)
	read();
	run();
	write();
	return 0;
}