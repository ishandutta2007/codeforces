#include <bits/stdc++.h>

using namespace std;
#define int long long

void read() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a % 2 == 0)
			cnt1++;
		else
			cnt2++;
	}
	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;
		if (b % 2 == 0 && cnt2 > 0)
			ans++, cnt2--;
		if (b % 2 == 1 && cnt1 > 0)
			ans++, cnt1--;
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