#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 300200;
std::mt19937 rd(time(0));
typedef unsigned u32;
u32 s0[maxn], s1[maxn], p[maxn];
int n, a[maxn];
int ans;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		p[i] = rd(), s1[i] = s1[i - 1] ^ p[i];
	}
	rep(i, 1, n) {
		cin >> a[i], s0[i] = s0[i - 1] ^ p[a[i]];
	}
	rep(i, 1, n) {
		static int now = 1;
		if(a[i] == 1) now = 0;
		else {
			now = std::max(now, a[i]);
			if(now <= i && (s0[i] ^ s0[i - now]) == s1[now]) {
				++ ans;
			}
		}
	}
	for(int i = n;i >= 1;--i) {
		static int now = 1;
		if(a[i] == 1) now = 0, ++ ans;
		else {
			now = std::max(now, a[i]);
			if(i + now - 1 <= n && (s0[i - 1] ^ s0[i + now - 1]) == s1[now]) {
				++ ans;
			}
		}
	}
	cout << ans << '\n';
}