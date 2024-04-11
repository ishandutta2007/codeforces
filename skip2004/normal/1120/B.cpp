#include<bits/stdc++.h>
const int maxn = 100100;
using std::cin;
using std::cout;
int n;
char a[maxn];
char b[maxn];
int res[maxn];
long long ans;
inline int good(int x) {
	return '0' <= x && x <= '9';
}
inline void output(int x, int w) {
	if(!good(a[x + 1] + w)) output(x + 1, -w);
	if(!ans) exit(0);
	cout << x << ' ' << w << '\n';
	a[x] += w, a[x + 1] += w, -- ans;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> a + 1 >> b + 1;
	for(int i = 1;i <= n;++i) {
		res[i] = (a[i] - b[i]) - res[i - 1];
		ans += std::abs(res[i]);
	}
	if(res[n] != 0) {
		puts("-1");
		return 0;
	}
	std::cout << ans << '\n';
	if(ans > 1e5) ans = 1e5;
	for(int i = 1;i <= n;++i) {
		while(a[i] != b[i]) {
			output(i, a[i] > b[i] ? -1 : 1);
		}
	}
}