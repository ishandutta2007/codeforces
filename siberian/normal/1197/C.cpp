#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
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
	ans = a[n - 1] - a[0];
	vector<int> d;
	for (int i = 1; i < n; i++)
		d.push_back(a[i] - a[i - 1]);
	sort(d.begin(), d.end());
	reverse(d.begin(), d.end());
	for (int i = 0; i < k - 1; i++)
		ans -= d[i];
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