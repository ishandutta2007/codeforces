#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int N = 200100;
int n, a[N];

int c0[N];
ll c1[N];

int max[N];
int can[N];
std::vector<int> vec[N];

inline void up(int & x, int y) {
	if(x < y) x = y;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;++i) cin >> a[i];
	rep(i, 1, n - 1) vec[std::__gcd(i, n)].push_back(i);
	ll ans = 0;
	rep(i, 1, n) if(vec[i].size()) {
		for(int x = 0;x < i;++x) max[x] = 0;
		for(int x = 0;x < n;x += i) {
			for(int j = 0;j < i;++j) up(max[j], a[x + j]);
		}
		for(int x = 0;x < n;x += i) {
			for(int j = 0;j < i;++j) can[x + j] = a[x + j] == max[j];
		}
		if(std::count(can, can + n, 1) == n) {
			ans += (ll) vec[i].size() * n;
			continue;
		} 
		memcpy(can + n, can, n << 2);
		memset(c0, 0, n + 1 << 2);
		memset(c1, 0, n + 1 << 3);
		int idx = std::find(can, can + n, 0) - can, lim = idx + n, c = 0;
		for(can[lim] = 0;idx <= lim;++idx) {
			if(can[idx]) ++ c;
			else {
				c0[c] += 1;
				c1[c] += c;
				c = 0;
			}
		}
		for(int i = n;i >= 0;--i) {
			c0[i] += c0[i + 1];
			c1[i] += c1[i + 1];
		}
		for(int x : vec[i]) {
			ans += c1[x] - (ll) c0[x] * (x - 1);
		}
	}
	cout << ans << '\n';
}