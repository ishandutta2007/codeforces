#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
int n, q, P, a[N], cnt, fib[N];

void inc(int x, int v) {
	if(x > n) return;
	if(a[x]) --cnt;
	a[x] = (a[x] + v) % P;
	if(a[x]) ++cnt;
}

void dec(int x, int v) {
	if(x > n) return;
	if(a[x]) --cnt;
	a[x] = (a[x] - v + P) % P;
	if(a[x]) ++cnt;
}

int main() {
	n = get(), q = get(), P = get();
	for(int i = 1; i <= n; i++) a[i] += get();
	for(int i = 1; i <= n; i++) a[i] -= get();
	for(int i = n; i >= 2; i--) a[i] = ((a[i] - a[i - 1]) % P - a[i - 2]) % P;
	for(int i = 1; i <= n; i++) a[i] = (a[i] + P) % P;
	fib[1] = 1;
	for(int i = 2; i <= n + 1; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % P;
	for(int i = 1; i <= n; i++) cnt += !!a[i];
	for(int t = 1; t <= q; t++) {
		char opt; int l, r;
		scanf("%c", &opt), l = get(), r = get();
		if(opt == 'A') inc(l, 1), dec(r + 1, fib[r - l + 2]), dec(r + 2, fib[r - l + 1]);
		else dec(l, 1), inc(r + 1, fib[r - l + 2]), inc(r + 2, fib[r - l + 1]);
		if(cnt) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}