#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 100005;
using ll = long long;
ll s[N], a[N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	for(int i = 0;i < t;++i) {
		int n, k;
		cin >> n >> k;
		int p = n + 1 - k;
		for(int i = p;i <= n;++i) {
			cin >> s[i];
		}
		for(int i = p + 1;i <= n;++i) {
			a[i] = s[i] - s[i - 1];
		}
		// a[1..p] <= a[p + 1]
		if(!std::is_sorted(a + p + 1, a + n + 1)) {
			cout << "No" << '\n';
			continue;
		}
		a[n + 1] = 1e9;
		if((ll) p * a[p + 1] >= s[p]) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}
}