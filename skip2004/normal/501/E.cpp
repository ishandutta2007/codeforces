#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

const int N = 100100;
int n, a[N];

inline int can(int x) {
	std::unordered_map<int, int> map;
	for(int i = 1;i <= x;++i) ++ map[a[i]];
	for(int i = 1;i <= n;++i) {
		int rev = n + 1 - i;
		if(rev > x) {
			if(i > x) {
				if(a[i] != a[rev]) return 0;
			} else {
				-- map[a[rev]];
			}
		}
	}
	int c = 0;
	for(auto x : map) {
		if(x.second < 0) return 0;
		c += x.second % 2;
	}
	return c <= 1;
}
inline int calc() {
	int l = -1, r = n;
	for(;l + 1 != r;) {
		int mid = l + r >> 1;
		if(can(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	return r;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 1;i <= n;++i) {
		if(a[i] == a[n + 1 - i]) {
			++ cnt;
		} else {
			break;
		}
	}
	if(cnt == n) {
		cout << (u64) n * (n + 1) / 2 << '\n';
	} else {
		if(!can(n)) {
			cout << 0 << '\n';
		} else {
			u64 x = n + 1 - calc();
			std::reverse(a + 1, a + n + 1);
			x += n + 1 - calc();
			cout << x * (cnt + 1) - (cnt + 1) * (cnt + 1) << '\n';
		}
	}
}