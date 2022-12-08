#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int a[7], n, b[N], cnt[N], tot;
struct Node {
	int pos, col;
	Node() {}
	Node(int x, int y) { pos = x, col = y; }
	bool operator <(Node y) const { return pos < y.pos; }
} p[N];

int main() {
	for(int i = 1; i <= 6; i++) a[i] = get();
	n = get(); 
	for(int i = 1; i <= n; i++) {
		b[i] = get();
		for(int j = 1; j <= 6; j++) p[(j - 1) * n + i] = Node(b[i] - a[j], i);
	}
	sort(p + 1, p + 1 + 6 * n);
	int ans = 1e9;
	for(int r = 1, l = 1; r <= 6 * n; r++) {
		if(!cnt[p[r].col]) tot++; cnt[p[r].col]++;
		while(cnt[p[l].col] > 1 && l < r) cnt[p[l++].col]--;
		if(tot == n) ans = min(ans, p[r].pos - p[l].pos);
	}
	printf("%d\n", ans);
	return 0;
}