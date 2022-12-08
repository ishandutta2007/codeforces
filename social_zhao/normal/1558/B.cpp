#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e6 + 5;
int n, P, f[N], suf[N];

int Sum(int l, int r) { return (suf[l] - suf[min(n + 1, r + 1)] + P) % P; }
void add(int &x, int y) { x = (x + y) % P; }

int main() {
	n = get(), P = get();
	f[n] = 1, suf[n] = 1;
	for(int i = n - 1; i >= 1; i--) {
		f[i] = suf[i + 1];
		for(int j = 2; i * j <= n; j++) add(f[i], Sum(i * j, i * j + (j - 1)));
		suf[i] = (suf[i + 1] + f[i]) % P;
	}
	printf("%d\n", f[1]);
	return 0;
}