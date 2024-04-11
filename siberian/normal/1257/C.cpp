#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void read() {

}

void run() {
	int n;
	cin >> n;
	int ans = 1e9;
	map <int, int> pos;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (pos.count(x))
			ans = min(ans, i - pos[x] + 1);
		pos[x] = i;
	}
	if (ans == 1e9)
		cout << -1 << endl;
	else
		cout << ans << endl;
}

void write() {

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	int t;
	cin >> t;
	while (t--)
	run();
	write();
	return 0;
}