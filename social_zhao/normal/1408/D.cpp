#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e3 + 5, S = 1e6 + 5;
int n, m, top, mx[S];
struct Point { int x, y; } a[N], b[N], st[N];

void qmax(int &x, int y) { x = max(x, y); }

int main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) a[i].x = get(), a[i].y = get();
	for(int i = 1; i <= m; i++) b[i].x = get(), b[i].y = get();
	sort(b + 1, b + 1 + m, [](Point x, Point y) { return x.x == y.x? x.y < y.y : x.x < y.x; });
	st[++top] = (Point){ -1, (int)1e9 };
	for(int i = 1; i <= m; i++) {
		while(st[top].y <= b[i].y) --top;
		st[++top] = b[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= top; j++) {
			if(st[j].x < a[i].x) continue;
			qmax(mx[st[j].x - a[i].x], max(st[j].y - a[i].y + 1, 0));
		}
	}
	for(int i = 1e6; i >= 0; i--) qmax(mx[i], mx[i + 1]);
	int ans = 0x3f3f3f3f;
	for(int i = 0; i <= 1e6; i++) ans = min(ans, i + mx[i]);
	cout << ans;
	return 0;
}