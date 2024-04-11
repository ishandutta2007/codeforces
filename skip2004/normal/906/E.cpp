#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 1000005;
struct info {
	std::pair<int, int> fi;
	inline info(int v = 1e9, int i = 114514) : fi(v, i) {}
} ;
inline info operator + (const info & x, const info & y) {
	return x.fi.first < y.fi.first ? x : y;
}

int c[N][26], fail[N], len[N], tot;
int diff[N], bigfail[N];
info atom[N];

inline void init() {
	fail[0] = 1, len[++tot] = -1;
	// root is 1
}
inline int get_fail(int o, char * x) {
	for(;*x != x[-len[o] - 1];)
		o = fail[o];
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
		if(fa != go) t = node[fa] + t;
		z = t + z;
	}
	return z;
}

char s[N], s0[N], s1[N];
int n, pos[N], dp[N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	init();

	cin >> s0 >> s1;
	n = strlen(s0) << 1;
	atom[0] = {0, 0};
	for(int i = 1, x = 1;i <= n;++i) {
		s[i] = (i & 1 ? s0 : s1)[i - 1 >> 1];
		x = append(x, s + i);
		if(i % 2) {
			query(x, i);
			continue;
		}
		atom[i] = query(x, i);
		auto res = atom[i].fi;
		res.first += 1;
		if(s[i] == s[i - 1])
			res = std::min(res, atom[i - 2].fi);
		dp[i] = res.first;
		pos[i] = res.second;
		atom[i] = info(dp[i], i);
	}
	if(dp[n] > 1e8) {
		cout << -1 << '\n';
		return 0;
	}
	cout << dp[n] << '\n';
	for(int i = n;i;i = pos[i]) {
		if(i - pos[i] > 2)
			cout << pos[i] / 2 + 1 << ' ' << i / 2 << '\n';
	}
}