#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;
char s[maxn];
int next[maxn][26], prev[maxn][26], n;
int next_sg[maxn][26], prev_sg[maxn][26];
int pre[maxn][26];

inline int calc(int l, int r) ;
inline int prv_sg(int r, int c) {
	if(~prev_sg[r][c]) return prev_sg[r][c];
	return prev_sg[r][c] = calc(prev[r][c] + 1, r);
}
inline int nxt_sg(int r, int c) {
	if(~next_sg[r][c]) return next_sg[r][c];
	return next_sg[r][c] = calc(r, next[r][c] - 1);
}
inline int pre_sum(int r, int c) {
	if(r == 0) return 0;
	if(~pre[r][c]) return pre[r][c];
	return pre[r][c] = pre_sum(prev[r - 1][c], c) ^ calc(prev[r - 1][c] + 1, r - 1);
}
inline int calc(int l, int r) {
	if(l > r) return 0;
	int w = -1;
	for(int i = 0;i < 26;++i) if(next[l][i] <= r) {
		int sg = prv_sg(r, i) ^ nxt_sg(l, i) ^ pre_sum(prev[r][i], i) ^ pre_sum(next[l][i], i);
		w &= ~(1 << sg);
	}
	return __builtin_ctz(w);
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> s + 1, n = strlen(s + 1);
	for(int i = 1;i <= n + 1;++i) {
		for(int j = 0;j < 26;++j) prev[i][j] = prev[i - 1][j];
		if(i != n + 1) prev[i][s[i] - 'a'] = i;
	}
	for(int i = 0;i < 26;++i) next[n + 1][i] = n + 1;
	for(int i = n;i >= 0;--i) {
		for(int j = 0;j < 26;++j) next[i][j] = next[i + 1][j];
		if(i) next[i][s[i] - 'a'] = i;
	}
	memset(next_sg, -1, sizeof next_sg);
	memset(prev_sg, -1, sizeof prev_sg);
	memset(pre, -1, sizeof pre);
	int q;
	cin >> q;
	for(int i = 0, l, r;i < q;++i) {
		cin >> l >> r;
		cout << (calc(l, r) ? "Alice" : "Bob") << '\n';
	}
}