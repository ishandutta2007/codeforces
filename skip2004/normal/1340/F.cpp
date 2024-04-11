#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
const int maxn = 100100;
const int bl = 1024;
static const int N = 1024;
int n, k, q;
int s[maxn];
 
struct block {
	int pop[N], c0;
	int push[N], c1;
	int ok;
} o[maxn / bl + 10];
 
inline int eql(const int * a, const int * b, const int len){ 
	for(int i = 0;i < len;++i) {
		if(a[i] != b[i]) return 0;
	}
	return 1;
}
inline bool ask(int l, int r) {
	static int st[maxn];
	int top = 0;
#define ps(x) \
		if(x > 0) { \
			st[++top] = x; \
		} else { \
			if(!top || st[top] != -x) return 0; \
			-- top; \
		}
	for(;l % bl && l <= r;++l) ps(s[l]);
	for(int i = l;i + bl - 1 <= r;i += bl) if(!o[i / bl].ok) return 0;
	for(;l + bl - 1 <= r;l += bl) {
		block &o = ::o[l / bl];
		if(top < o.c0 || !eql(st + top - o.c0 + 1, o.pop + N - o.c0, o.c0)) return 0;
		top -= o.c0;
		memcpy(st + top + 1, o.push + 1, o.c1 << 2);
		top += o.c1;
	}
	for(;l <= r;++l) ps(s[l]);
	return top == 0;
}
inline void init(int id) {
	block&o = ::o[id];
	o.c0 = o.c1 = 0;
	o.ok = 1;
	static int st[maxn];
	int top = 0;
	const int L = id * bl, R = std::min(n - 1, id * bl + bl - 1);
	for(int i = L;i <= R;++i) {
		if(s[i] > 0) {
			st[++top] = s[i];
		} else {
			if(top && st[top] != -s[i]) {
				o.ok = 0;
				return ;
			} else {
				if(top) {
					-- top;
				} else {
					o.pop[N - ++o.c0] = -s[i];
				}
			}
		}
	}
	memcpy(o.push + 1, st + 1, top << 2);
	o.c1 = top;
}
 
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> k;
	for(int i = 0;i < n;++i) {
		std::cin >> s[i];
	}
	for(int i = 0;i <= (n - 1) / bl;++i) init(i);
	std::cin >> q;
	for(int i = 0;i < q;++i) {
		int opt, pos, l, r;
		std::cin >> opt;
		if(opt == 1) {
			std::cin >> pos;
			-- pos;
			std::cin >> s[pos];
			init(pos / bl);
		} else {
			std::cin >> l >> r;
			std::cout << (ask(l - 1, r - 1) ? "Yes" : "No") << '\n';
		}
	}
}