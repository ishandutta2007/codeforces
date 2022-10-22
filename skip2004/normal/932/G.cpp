#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 1000005;
const int mod = 1e9 + 7;
struct info {
	int w;
} ;
inline info operator + (const info & x, const info & y) {
	return {(x.w + y.w) % mod};
}

int c[N][26], fail[N], len[N], tot;
int diff[N], bigfail[N];
info atom[N];

inline void init() {
	bigfail[0] = fail[0] = 1, len[++tot] = -1;
	// root is 1
}
inline int get_fail(int o, char * x) {
	for(;*x != x[-len[o] - 1];) {
		o = (*x != x[-len[fail[o]] - 1] ? bigfail : fail)[o];
	}
	return o;
}
inline int append(int o, char * x) {
	o = get_fail(o, x);
	int & p = c[o][*x - 'a'];
	if(!p) {
		fail[++tot] = c[get_fail(fail[o], x)][*x - 'a'];
		len[p = tot] = len[o] + 2;
		diff[p] = len[p] - len[fail[p]];
		bigfail[p] = diff[p] == diff[fail[p]] ? bigfail[fail[p]] : fail[p];
	}
	return p;
}
info node[N];
inline info query(int x, int i) {
	info z = {};
	for(;x;x = bigfail[x]) {
		const int go = bigfail[x], fa = fail[x];
		info & t = node[x] = atom[i - len[go] - diff[x]];
		if(fa != go) t = node[fa] + t, node[fa] = {128497124};
		z = t + z;
	}
	return z;
}

char s[N], buf[N];
int n, pos[N], dp[N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	init();

	atom[0] = {1};

	cin >> buf + 1;
	n = strlen(buf + 1);
	const int M = n / 2;
	for(int i = 1;i <= M;++i) {
		s[i + i] = buf[i];
		s[i + i - 1] = buf[n - i + 1];
	}
	for(int i = 1, x = 1;i <= n;++i) {
		x = append(x, s + i);
		if(i % 2) {
			query(x, i);
			continue;
		}
		atom[i] = query(x, i);
	}
	cout << atom[n].w << '\n';
}