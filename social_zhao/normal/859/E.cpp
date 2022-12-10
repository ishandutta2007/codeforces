#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, P = 1e9 + 7;
int n, _x[N], _y[N], fa[N], sze[N], cnt[N], slf[N], fix[N];

int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }

void merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) ++cnt[x];
	else sze[x] += sze[y], cnt[x] += cnt[y], ++cnt[x], slf[x] |= slf[y], fa[y] = x;
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) {
		_x[i] = get(), _y[i] = get();
		if(_x[i] == _y[i]) fix[_x[i]] = 1;
	}
	for(int i = 1; i <= 2 * n; i++) fa[i] = i, sze[i] = 1, cnt[i] = 0, slf[i] = fix[i];
	for(int i = 1; i <= n; i++) if(_x[i] != _y[i] && fix[_x[i]] && fix[_y[i]]) return printf("0\n"), 0;
	for(int i = 1; i <= n; i++) merge(_x[i], _y[i]);
	int ans = 1;
	for(int i = 1; i <= 2 * n; i++) if(fa[i] == i) {
		if(cnt[i] > sze[i]) return printf("0\n"), 0;
		else if(cnt[i] == sze[i]) {
			if(!slf[i]) ans = ans * 2 % P;
		}
		else ans = ans * sze[i] % P;
	}
	cout << ans;
	return 0;
}