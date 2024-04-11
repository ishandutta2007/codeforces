#include<bits/stdc++.h>
using std::cin;
using std::cout;
int t;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		int n;
		cin >> n;
		std::vector<int> a(n + 1);
		auto calc = [&](int x) {
			std::vector<int> b;
			int p = 0;
			for(int i = 1;i <= n;++i) {
				if(a[i] && x) {
					-- x;
					++ p;
				} else {
					b.push_back(a[i]);
				}
			}
			for(int i = b.size() - 1;i >= 0;--i) {
				if(p && !b[i]) b[i] = 1, -- p;
			}
			return is_sorted(b.begin(), b.end());
		};
		for(int i = 1;i <= n;++i) cin >> a[i];
		int l = -1, r = n + 2;
		for(;l + 1 < r;) {
			int mid = (l + r) >> 1;
			if(calc(mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}
		cout << r << '\n';
	}
}