#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline void mxe(int &a, int b) {
	if (b > a) a = b;
}

void solve() {
	int n;
	cin >> n;
	vector<int> first(n, -1), last(n, -1), num(n, 0), a(n);
	int kk = -1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; x--;
		a[i] = x;
		num[x]++;
		last[x] = i;
		if (first[x] == -1) first[x] = i;
	}
	for (int i = 0; i < n; i++) if (a[i] == a[n - 1] && kk == -1) kk = i;

	int mx = 0;
	vector<int> nx(n + 1, 0);
	vector<int> nn(n + 1, 0);
	int mx_n = 0;
	for (int i = n - 1; i >= 0; i--) {
		nn[a[i]]++;
		mxe(mx_n, nn[a[i]]);
		nx[i] = mx_n;
	}

	vector<int> dp(n + 1, 0);	

	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (first[x] == i)
			mxe(dp[last[x] + 1], dp[i] + num[x]);		
		mxe(dp[i + 1], dp[i]);	

		mxe(mx, dp[i] + nx[i]);	
	}
	cout << n - mx << "\n";
}

int main() {
	int t = 1;
#ifdef SERT
	t = 3;
#endif
	// cin >> t;
	while (t--)
		solve();
}