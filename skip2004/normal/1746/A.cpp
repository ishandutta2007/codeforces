#include<bits/stdc++.h>
using std::cin;
using std::cout;
int t;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		int n, k, o = 0;
		cin >> n >> k;
		for(int i = 0, x;i < n;++i) {
			cin >> x, o |= x;
		}
		cout << (o ? "YES" : "NO") << '\n';
	}
}