#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1 << 18, P = 998244353;
int n, node, f[N], lc[N], rc[N];
char s[N];
string str[N];

int chk(int x, int y) {
	if(!x && !y) return 1;
	if(s[x] != s[y]) return 0;
	return chk(lc[x], lc[y]) && chk(rc[x], rc[y]);
}

void dfs(int u) {
	if(!lc[u] && !rc[u]) return f[u] = 1, str[u] += s[u], void();
	dfs(lc[u]), dfs(rc[u]);
	if(str[lc[u]] > str[rc[u]]) swap(lc[u], rc[u]);
	if(chk(lc[u], rc[u])) f[u] = f[lc[u]] * f[rc[u]] % P;
	else f[u] = f[lc[u]] * f[rc[u]] * 2 % P;
	str[u] += s[u], str[u] += str[lc[u]], str[u] += str[rc[u]];
//	cout << u << " " << str[u] << " " << str[lc[u]] << " " << str[rc[u]] << endl;
}

main() {
	n = get(), node = (1 << n) - 1;
	scanf("%s", s + 1);
	for(int i = 1; i * 2 <= node; i++) lc[i] = i * 2, rc[i] = i * 2 + 1;
	dfs(1);
	cout << f[1] << endl;
	return 0;
}