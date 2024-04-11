#include<bits/stdc++.h>
const int maxn = 100100;
typedef long long ll;
using std::cin;
using std::cout;
int n, m, k;
std::vector<int> v0[maxn], v1[maxn];
inline int gt(std::vector<int> & v, int x, int max) {
	auto res = upper_bound(v.begin(), v.end(), x);
	return res == v.end() ? max : std::min(*res, max);
}
inline int ls(std::vector<int> & v, int x, int max) {
	auto res = upper_bound(v.rbegin(), v.rend(), x, std::greater<int>());
	return res == v.rend() ? max : std::max(*res, max);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= k;++i) {
		int x, y;
		cin >> x >> y;
		v0[x].push_back(y);
		v1[y].push_back(x);
	}
	for(int i = 1;i <= n;++i) sort(v0[i].begin(), v0[i].end());
	for(int i = 1;i <= m;++i) sort(v1[i].begin(), v1[i].end());
	int x0 = 0, x1 = n + 1, y0 = 0, y1 = m + 1;
	int nx = 1, ny = 1;
	ll cnt = 0;
	const auto go = [&](int x, int y, int must) {
		cnt += std::abs(nx - x) + std::abs(ny - y);
		if(x == nx && y == ny) {
			if(must)
				cout << (cnt + k + 1 == (ll) n * m ? "Yes" : "No") << '\n', exit(0);
		}
		nx = x;
		ny = y;
	};
	for(int yes = 0;;) {
		go(nx, gt(v0[nx], ny, y1) - 1, yes), x0 = nx, yes = 1;
		go(gt(v1[ny], nx, x1) - 1, ny, 1), y1 = ny;
		go(nx, ls(v0[nx], ny, y0) + 1, 1), x1 = nx;
		go(ls(v1[ny], nx, x0) + 1, ny, 1), y0 = ny;
	}
}