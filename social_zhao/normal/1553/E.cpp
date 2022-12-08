#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
int n, m, p[N], to[N], cnt[N * 2], bin[N], top, fa[N];

int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }

int chk(int k) {
	for(int i = 1; i <= n; i++) {
		int to_be = (p[i] + k - 1) % n + 1;
		int not_to_be = i;
		to[not_to_be] = to_be;
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= n; i++) {
		if(find(i) != find(to[i])) fa[find(i)] = find(to[i]);
	}
	int res = 0;
	for(int i = 1; i <= n; i++) res += i == fa[i];
	return n - res <= m;
}

void solve() {
	n = get(), m = get();
	top = 0;
	for(int i = 1; i <= n; i++) p[i] = get();
	for(int i = 0; i <= 2 * n; i++) cnt[i] = 0;
	for(int i = 1; i <= n; i++) ++cnt[(i - p[i] + n) % n];
	for(int i = 0; i < n; i++) 
		if(cnt[i] >= n - 2 * m && chk(i)) 
			bin[++top] = i;
	printf("%d ", top);
	for(int i = 1; i <= top; i++) printf("%d ", bin[i]);
	printf("\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}