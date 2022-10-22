#include<bits/stdc++.h>
using std::cin;
using std::cout;
using ll = long long;
int t;
int rank[1 << 20];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		int n;
		cin >> n;
		std::vector<int> a(n + 1);
		for(int i = 1;i <= n;++i) cin >> a[i], rank[i] = i;
		std::sort(rank + 2, rank + n + 1, [&](int x, int y) { return a[x - 1] - a[x] < a[y - 1] - a[y]; });
		for(int i = 1;i <= n;++i) cout << rank[i] << " \n"[i == n];
	}
}