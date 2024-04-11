#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> a;
int n;
void read() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(a.begin(), a.end(), a[i] - 5) - a.begin();
		ans = max(ans, i - pos + 1); 
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