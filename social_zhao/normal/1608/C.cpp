#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, mx[N];
struct Node { int a, b, id; } p[N];
int ans[N];

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) p[i].a = get(), p[i].id = i;
	for(int i = 1; i <= n; i++) p[i].b = get();
	for(int i = 1; i <= n; i++) ans[i] = 0;
	sort(p + 1, p + 1 + n, [](Node x, Node y) { return x.a < y.a; });
	for(int i = 1; i <= n; i++) mx[i] = max(mx[i - 1], p[i].b);
	ans[p[n].id] = 1;
	int mn = p[n].b;
	for(int i = n - 1; i >= 1; i--) {
		if(mx[i] > mn) ans[p[i].id] = 1, mn = min(mn, p[i].b);
	}
	for(int i = 1; i <= n; i++) printf("%d", ans[i]); printf("\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
5
5 1 2 3 4 
3 2 5 4 1 

*/