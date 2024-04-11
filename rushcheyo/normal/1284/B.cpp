#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;
int n, mn[N], mx[N];
vector<int> mn_, mn1, mx_, mx1;
bool ok[N];
vector<int> v[N];

ll count(vector<int> a, vector<int> b) {
	sort(a.begin(), a.end());
	ll ans = 0;
	for (int x : b) ans += lower_bound(a.begin(), a.end(), x) - a.begin();
	return ans;
}

int main() {
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x), v[i].resize(x);
		mn[i] = 1 << 30;
		for (int j = 0; j < x; ++j) {
			scanf("%d", &v[i][j]);
			ok[i] |= v[i][j] > mn[i];
			mx[i] = max(mx[i], v[i][j]);
			mn[i] = min(mn[i], v[i][j]);
		}
		mn_.push_back(mn[i]), mx_.push_back(mx[i]);
		if (ok[i]) mn1.push_back(mn[i]), mx1.push_back(mx[i]), ++cnt;
	}
	cout << 1ll * cnt * n * 2 + count(mn_, mx_) - 1ll * cnt * cnt - count(mn1, mx_) - count(mn_, mx1) + count(mn1, mx1) << endl;
}