#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, p;

void read() {
	cin >> n >> p;
}

int ans = -1;

int get(int x) {
	int ans = 0;
	while (x) {
		ans += x % 2;
		x /= 2;
	}	
	return ans;
}

void run() {
	for (int i = 1; i < 50; i++) {
		if (n - p * i >=i && get(n - p * i) <= i) {
			ans = i;
			break;
		}
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