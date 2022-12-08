#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 6e5 + 5;
int n, b[N];
struct Node {
	int l, r;
	bool operator <(Node y) { return r < y.r; }
} node[N];

int main() {
	n = get();
	for(int i = 1, x, y; i <= n; i++) x = get(), y = get(), node[i].l = x - y, node[i].r = x + y;
	sort(node + 1, node + 1 + n);
	int lst = -0x3f3f3f3f, ans = 0;
	for(int i = 1; i <= n; i++) if(node[i].l >= lst) ans++, lst = node[i].r;
	printf("%d\n", ans);
	return 0;
}