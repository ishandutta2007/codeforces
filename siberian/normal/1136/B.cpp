#include <bits/stdc++.h>

using namespace std;
#define int long long

void read() {
	int n, k;
	cin >> n >> k;
	int ans = n + 1;
	ans += n - 1;
	ans += min(k - 1, n - k);
	ans += n;
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