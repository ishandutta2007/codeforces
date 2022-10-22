#include<bits/stdc++.h>
int n, t;
using std::cin;
using std::cout;
const int maxn = 100100;

std::mt19937 rd(time(0));
class yhx {
	int a[maxn], t;
	public :
	inline void init() {
		cin >> n >> t;
		:: t = t;
		return ;
		n = (rd() % 20 | 1);
		for(int i = 1;i <= n;++i) {
			t += a[i] = rd() % 2;
			std::cout << a[i];
		}
		std::cout << '\n';
		::t = t;
	}
	inline int flip(int l, int r) {
		std::cout << "? " << l << ' ' << r << std::endl;
		std::cin >> t;
		return ::t = t;
//		std::cout << l << ' ' << r << '\n';
		if(rd() & 1) {
			for(int i = 1;i <= r;++i) {
				t -= a[i], t += a[i] ^= 1;
			}
		} else {
			for(int i = l;i <= n;++i) {
				t -= a[i], t += a[i] ^= 1;
			}
		}
		return ::t = t;
	}
} A;

inline void suf(int p) {
	int now = t + n - p + 1 & 1;
	A.flip(p, p + n % 2);
	for(;now + t & 1;) {
		A.flip(p, p + n % 2);
		A.flip(p, p + n % 2);
	}
}
inline void flip(int p) {
	if(!p) return ;
	if(p == 1 && n % 2) {
		return flip(n), suf(2);
	}
	int now = t + p & 1;
	A.flip(p - n % 2, p);
	for(;now + t & 1;) {
		A.flip(p - n % 2, p);
		A.flip(p - n % 2, p);
	}
}

int ans[maxn];
int main() {
	A.init();
	if(n == 1) {
		ans[1] = t;
	} else {
		for(int i = n;i >= 1;--i) {
			int now = t;
			flip(i - 1);
			flip(i);
			ans[i] = t == now + 1 ? 0 : 1;
		}
	}
	std::cout << '!' << ' ';
	for(int i = 1;i <= n;++i) {
		std::cout << ans[i];
	}
	std::cout << '\n';
}