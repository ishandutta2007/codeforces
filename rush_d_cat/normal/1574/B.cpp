#include <bits/stdc++.h>
typedef long long ll;
const int N = 100000 + 10;

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(0);
	int t;
	std::cin >> t;

	while (t --) {
		int a, b, c, m;
		std::cin >> a >> b >> c >> m;
		int mx = a + b + c - 3;
		std::vector<int> v = {a, b, c};
		std::sort(v.begin(), v.end());
		
		int mn = std::max(0, v[2] - 1 - v[0] - v[1]);
		if (mx < m || m < mn) 
			std::cout << "NO" << "\n";
		else 
			std::cout <<"YES" << "\n";
	}
}