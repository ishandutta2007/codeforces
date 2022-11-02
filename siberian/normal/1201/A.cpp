#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define all(a) a.begin(), a.end()

template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (y > x) x = y;}
template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}

int n, m;
vector<string> s;
void read() {
	cin >> n >> m;
	s.resize(n);
	for (auto &i : s)
		cin >> i;
}

int ans;

void run() {
	ans = 0;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		map <char, int> cnt;
		for (int j = 0; j < n; j++) {
			cnt[s[j][i]]++;
		}
		int mx = 0;
		for (auto j : cnt)
			chkmax(mx, j.second);
		ans += x * mx;
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