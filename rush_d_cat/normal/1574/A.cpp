#include <bits/stdc++.h>
typedef long long ll;
const int N = 100000 + 10;

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(0);
	int t;
	std::cin >> t;

	while (t --) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < i; j ++) {
				std::cout << '(';
			}
			for (int j = 0; j < i; j ++) {
				std::cout << ')';
			}
			for (int j = 0; j < n - i; j ++) {
				std::cout << '(';
			}
			for (int j = 0; j < n - i; j ++) {
				std::cout << ')';
			}
			std::cout << "\n";
		}
	}
}