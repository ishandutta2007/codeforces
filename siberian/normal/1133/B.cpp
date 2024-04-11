#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, k;
void read() {
 	cin >> n >> k;
 	map <int, int> a;
 	for (int i = 0; i < n; i++) {
 		int x;
 		cin >> x;
 		x %= k;
 		a[x]++;
 	}
 	int ans = 0;
 	for (auto i : a) {
 		if (i.first * 2 == k || i.first == 0) 
 			ans += (i.second / 2) * 2;
 		else
 			ans += min(i.second, a[k - i.first]);
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