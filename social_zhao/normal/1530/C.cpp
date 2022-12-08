#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int a[N], b[N], n;

int chk(int x) {
	int tot = n + x, oth = tot / 4;
	if(oth >= n) return 1;
	else if(oth == 0) return a[n] + 100 * x >= b[n];
	else return a[n] - a[oth] + 100 * x >= b[n] - b[max(0, oth - x)];
}

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++) b[i] = get();
	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; i++) a[i] += a[i - 1], b[i] += b[i - 1];
	for(int i = 0; i <= n; i++)
		if(chk(i)) {
			printf("%d\n", i);
			return;
		}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
4
10 20 30 40
100 100 100 100
*/