#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
vector<int> g[N];
int cnt(vector<int> & v, int x) {
	return upper_bound(v.begin(), v.end(), x) - v.begin();
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		g[a[i]].push_back(i);
	}
	while (q --) {
		int l, r; cin >> l >> r; l--, r--;
		int mx = 0;
		for (int i = 1; i <= 40; i ++) {
			int pos = l + 1LL * rand() * rand() % (r - l + 1);
			mx = max(mx, cnt(g[a[pos]], r) - cnt(g[a[pos]], l-1));
			if (mx * 2 >= (r - l + 1)) break;
		}	
		int len = r - l + 1;
		//cout << mx << endl;
		if (mx * 2 <= len) {
			cout << 1 << endl;
		} else {
			int r = mx - (len - mx) - 1;
			cout << (r + 1) << endl;
		}
	}
}