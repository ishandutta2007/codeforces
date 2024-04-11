#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}

const int INF = 1e18;

vector<int> ans;

void run() {
	pair <int, int> fans = {0, 1};
	for (int i = 1; i < INF; i *= 2) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			cnt += (a[j] % i == 0) && ((a[j] / i) % 2 != 0);
		}
		chkmax(fans, make_pair(cnt, i));
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % fans.second == 0 && (a[i] / fans.second) % 2 != 0) continue;
		ans.push_back(a[i]);
	}
	sort(a.begin(), a.end());
}

void write() {
	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
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