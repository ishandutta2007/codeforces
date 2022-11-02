#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, k;
vector<int> a;

void read() {
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}
int ans = 0;
void run() {
	vector<int> suff(n, 0);
	suff[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		suff[i] = suff[i + 1] + a[i];

	ans = suff[0];

	sort(suff.begin() + 1, suff.end());
	reverse(suff.begin(), suff.end());

	for (int i = 0; i < k - 1; i++)
		ans += suff[i];
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