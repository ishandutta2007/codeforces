#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define all(a) a.begin(), a.end()

template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (y > x) x = y;}
template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}

int n, k;
vector<int> a;

void read() {
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}

int ans;

void run() {
	sort(a.begin(), a.end());
	int pos = n / 2 + 1;
	//cout << "pos = " << pos << endl;
	//cout << "n / 2 = " << n / 2 << endl;
	int cnt = 1;
	while (pos < n && k > 0) {
		if (cnt * (a[pos] - a[pos - 1]) <= k) {
			k -= cnt * (a[pos] - a[pos - 1]);
			cnt++;
			pos++;
		}
		else {
			break;
		}
	}
	for (int i = pos - 1; i >= n / 2; i--) {
		a[i] = a[pos - 1] + k / cnt;
	}

	sort(a.begin(), a.end());
	ans = a[n / 2];
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