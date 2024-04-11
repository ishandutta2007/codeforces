#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e3 + 5;
int n, a[N];

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	printf("%d\n", 3 * n);
	for(int i = 1; i <= n; i += 2) {
		printf("1 %d %d\n", i, i + 1);
		printf("2 %d %d\n", i, i + 1);
		printf("1 %d %d\n", i, i + 1);
		printf("1 %d %d\n", i, i + 1);
		printf("2 %d %d\n", i, i + 1);
		printf("1 %d %d\n", i, i + 1);
	}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}