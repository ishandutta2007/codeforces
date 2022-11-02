#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, m, ta, tb, k; 
vector<int> a;
vector<int> b;
void read() {
	cin >> n >> m >> ta >> tb >> k;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	b.resize(m);
	for (auto &i : b)
		cin >> i;
}
const int INF = 1e18;
int ans = 0;
void run() {
	if (k >= n || k >= m){
		ans = INF;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i > k)
			break;

		auto pos = lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
		//cout << "pos = " << pos << endl;
		if (m - pos <= k - i) {
			ans = INF;
			return; 
		}
		//cout << "b[] = " << b[pos + k - i] + tb << endl;
		ans = max(ans, b[pos + k - i] + tb);
	}
}

void write() {
	//cout << ans << endl; 
	if (ans == INF)
		ans = -1;
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