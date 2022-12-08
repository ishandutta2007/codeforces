#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, a[N], mp;

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	mp = 1;
	for(int i = 2; i <= n; i++) if(a[i] < a[mp]) mp = i;
	printf("%d\n", n - (mp == n));
	if(mp != n) printf("%d %d %d %d\n", mp, n, a[n], a[mp]), swap(a[n], a[mp]);
	for(int i = 1; i < n; i++) printf("%d %d %d %d\n", i, n, a[n] + (n - i), a[n]);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}