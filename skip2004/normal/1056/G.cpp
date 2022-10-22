#include<bits/stdc++.h>
typedef long long ll;
using std::cin;
using std::cout;
const int maxn = 100100;
int n, m, s;
ll t;
int f[2][maxn], * to = f[0], * lol = f[1];
 
int jump[40][maxn];
inline void cpy(int * a, int b, int len) {
	b %= n;
	if(b + len < n) {
		memcpy(a, to + b, len << 2);
	} else {
		memcpy(a, to + b, n - b << 2);
		memcpy(a + n - b, to, len - (n - b) << 2);
	}
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> s >> t, -- s;
	for(int i = 0;i < n;++i) to[i] = i;
	for(int T = 0;T < n;++T) {
		cpy(lol, T, m);
		cpy(lol + m, m - T + n, n - m);
 
		std::swap(to, lol);
	}
	for(int i = 0;i < n;++i) jump[0][i] = to[i];
	for(int i = 1;i < 40;++i) {
		for(int j = 0;j < n;++j) {
			jump[i][j] = jump[i - 1][jump[i - 1][j]];
		}
	}
	for(;t % n != 0;--t) {
		if(s < m) {
			s = (s + t) % n;
		} else {
			s = ((s - t) % n + n) % n;
		}
	}
	t /= n;
	for(int i = 39;i >= 0;--i) if(t >> i & 1) {
		s = jump[i][s];
	}
	cout << s + 1 << '\n';
}