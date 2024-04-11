#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
const int MAXN = 2*1e5 + 10;
int a[MAXN], b[MAXN];
void read() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
}
int ans;
void run() {
	int cnt0 = 0;
	int cnt1 = 0;
	map <pair<int, int> , int> h1, h2; 
	for (int i = 0; i < n; i++) {
		if (a[i] == 0 && b[i] == 0) {
			cnt0++;
			continue;
		}
		if (a[i] != 0 && b[i] == 0) {
			cnt1++;
			continue;
		}
		if (a[i] == 0 && b[i] != 0)
			continue;
		if (a[i] * b[i] > 0)
		{
			a[i] = abs(a[i]);
			b[i] = abs(b[i]);
			int g = __gcd(a[i], b[i]);
			a[i] /= g;
			b[i] /= g;
			h1[{a[i], b[i]}]++;
		}

		if (a[i] * b[i] < 0)
		{
			a[i] = abs(a[i]);
			b[i] = abs(b[i]);
			int g = __gcd(a[i], b[i]);
			a[i] /= g;
			b[i] /= g;
			h2[{a[i], b[i]}]++;
		}
	}
	ans = cnt1;
	for (auto i : h1)
		ans = max(ans, i.second);
	for (auto i : h2)
		ans = max(ans, i.second);
	ans += cnt0;
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