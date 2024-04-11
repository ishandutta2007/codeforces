#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long x, long long y) {
	while (y != 0) {
		long long r = x;
		x = y;
		y = r % y;
	}
	return x;
}
int n, a[109]; bool vis[109];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
	long long ret = 1;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vector<int> p;
			int pos = i;
			while (true) {
				p.push_back(pos);
				pos = a[pos];
				if (find(p.begin(), p.end(), pos) != p.end()) break;
			}
			if (pos == i) {
				int res = p.size();
				if (res % 2 == 0) res /= 2;
				ret = ret / gcd(ret, res) * res;
			}
			else {
				ret = -1; break;
			}
		}
	}
	cout << ret << endl;
	return 0;
}