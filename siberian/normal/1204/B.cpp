#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
int l, r;

void read() {
	cin >> n >> l >> r;
}

int ans1, ans2;

void run() {
	ans1 = 0;
	for (int i = 0; i < l; i++)
		ans1 += pow(2, i);
	ans1 += n - l;

	ans2 = 0;
	for (int i = 0; i < r; i++)
		ans2 += pow(2, i);
	ans2 += pow(2, r - 1) * (n - r);
}

void write() {
	cout << ans1 << " " << ans2 << endl;
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