#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, a[N];

int to(int i) { return i - a[i]; }

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	int p1 = n, p2 = to(n);
	while(p1 != p2) p1 = to(p1), p2 = to(to(p2));
	int cnt = 1;
	while(to(p2) != p1) p2 = to(p2), ++cnt;
	printf("%d\n", cnt);
	for(int i = 1; i <= cnt; i++) printf("%d ", p2), p2 = to(p2);
	printf("\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}