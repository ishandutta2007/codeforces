#include <bits/stdc++.h>
typedef long long ll;
const int N = 100000 + 10;

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(0);

	int n;
	std::cin >> n;

	std::vector<std::vector<int> > a(n, std::vector<int>(0));
	for (int i = 0; i < n; i ++) {
		int c; 
		std::cin >> c;
		for (int j = 0; j < c; j ++) {
			int x;
			std::cin >> x;
			a[i].emplace_back(x);
		}
	}

	int m;
	std::cin >> m;
	

	std::vector<std::vector<int> > b(m, std::vector<int>(n));
	for (int i = 0; i < m; i ++) 
		for (int j = 0; j < n; j ++)
			std::cin >> b[i][j], b[i][j] --;

	std::sort(b.begin(), b.end());

	ll ans = 0;
	std::vector<int> result;
	
	{
		std::vector<int> tmp;
		for (int i = 0; i < n; i ++)
			tmp.emplace_back((int)a[i].size() - 1);
		ll sum = 0;
		for (int j = 0; j < n; j ++)
			sum += a[j][tmp[j]];
		
		if (! std::binary_search(b.begin(), b.end(), tmp)) {
			if (sum > ans) {
				ans = sum; result = tmp;
			}
		}
	}

	for (int i = 0; i < m; i ++) {
		std::vector<int> tmp = b[i];
		ll sum = 0;
		for (int j = 0; j < n; j ++)
			sum += a[j][tmp[j]];
	
		for (int j = 0; j < n; j ++) {
			if (tmp[j] > 0) {
				tmp[j] --;
				if (! std::binary_search(b.begin(), b.end(), tmp)) {					
					if (sum - a[j][b[i][j]] + a[j][b[i][j] - 1] > ans) {
						ans = sum - a[j][b[i][j]] + a[j][b[i][j] - 1];
						result = tmp;
					}
				}
				tmp[j] ++;
			}
		}
	}
	for (int i = 0; i < n; i ++) std::cout << result[i] + 1 << " \n"[i==n-1];
}