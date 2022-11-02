#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
vector <int> arr;


void read() {
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	int mx = arr[n - 1];
	for (int i = n - 1; i >= 0; i--) {
	    ans += min(mx, arr[i]);
	    mx = min(mx - 1LL, arr[i] - 1LL);
	    if (mx <= 0)
	        break;
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