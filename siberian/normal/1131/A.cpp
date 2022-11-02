#include <bits/stdc++.h>

using namespace std;

#define int long long
int w1, h1, w2, h2;
void read() {
	cin >> w1 >> h1 >> w2 >> h2;
	int ans = w1 + 2 + w2 + 2 + h1 + h2 + h1 + h2;
	if (w2 != w1) {
		ans += abs(w2 - w1);
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