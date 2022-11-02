#include <bits/stdc++.h>

using namespace std;
#define int long long


int n, k;
void read() {
	cin >> n >> k;
}
string ans;
void run() {
	k = (n - k) / 2 + 1;

	string help = "";
	for (int i = 0; i < k - 1; i++)
		help += "1";
	help += "0";

	ans = "";
	for (int i = 0; i < n; i++) {
		ans += help[i % k];
	}
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