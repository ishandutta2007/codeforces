#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t --) {
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> c(n + 1);
		vector<int> a(n + 1, 0), b(n + 1, 0);
		for (int i = 1; i <= n; i ++) {
			cin >> c[i];
			if (i <= l) {
				a[c[i]] ++;
			} else {
				b[c[i]] ++;
			}
		}

		if (l > r) {
			swap(l, r); swap(a, b);
		}
		int cnt = (r - l) / 2;
		
		priority_queue<int> q;
		for (int i = 1; i <= n; i ++) {
			if (b[i] >= a[i]) {
				q.push(b[i] - a[i]);
			}
		}
		for (int i = 1; i <= cnt; i ++) {
			int x = q.top();
			q.pop();
			x -= 2; if (x >= 0) q.push(x);
		}
		int ans = cnt;
		while (q.size()) {
			ans += q.top(); q.pop();
		}
		cout << ans << endl;
	}
}