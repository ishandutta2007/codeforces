#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;

int n, m;

const int N = 100001;
using ll = long long;
int c[N];
ll s[N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for(int i = 0;i < n;++i) {
		for(int j = 0;j < m;++j) {
			cin >> a[i][j];
		}
	}
	ll ans = 0;
	for(int i = 0;i < n;++i) {
		for(int j = 0;j < m;++j) {
			ans += (ll) i * c[a[i][j]] - s[a[i][j]];
		}
		for(int j = 0;j < m;++j) {
			c[a[i][j]] += 1;
			s[a[i][j]] += i;
		}
	}
	memset(c, 0, sizeof(c));
	memset(s, 0, sizeof(s));
	for(int j = 0;j < m;++j) {
		for(int i = 0;i < n;++i) {
			ans += (ll) j * c[a[i][j]] - s[a[i][j]];
		}
		for(int i = 0;i < n;++i) {
			c[a[i][j]] += 1;
			s[a[i][j]] += j;
		}
	}
	cout << ans << '\n';
}