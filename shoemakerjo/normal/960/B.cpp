#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int k, k1, k2;
	cin >> k1 >> k2;
	k = k1 + k2;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	priority_queue<int> diffs;
	for (int i = 0; i < n; i++) {
		diffs.push(abs(a[i]-b[i]));
	}
	while (k--) {
		int cur = diffs.top(); diffs.pop();
		cur--;
		if (cur == -1) cur = 1;
		diffs.push(cur);
	}
	ll ans = 0LL;
	while (diffs.size() > 0) {
		int tp = diffs.top(); diffs.pop();
		ans += tp*1LL*tp;
	}
	cout << ans << endl;
	cin >> n;
	
}