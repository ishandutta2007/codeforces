#include <bits/stdc++.h>

using namespace std;
#define int long long
void read() {
	int n;
	cin >> n;
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	int k;
	cin >> k;
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i].second >= k)
			ans++;
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