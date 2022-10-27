#include <bits/stdc++.h>
using namespace std;

const int N = 20000 + 10;
int t;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) 
			cin >> a[i];
		sort(a.begin(), a.end());

		vector<ll> pre(n);
		pre[0] = a[0];
		for (int i = 1; i < n; i ++) 
			pre[i] = pre[i-1] + a[i];
		bool ok = false;
		for (int i = 1; i < n; i ++) {
			if (pre[i] < pre[n-1] - pre[n-1-i]) ok = true;
		}
		cout << (ok?"YES":"NO") << "\n";
	}
}