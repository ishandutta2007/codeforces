#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n, a, b;

void solve() {
	n = get(), a = get(), b = get();
	if(abs(a - b) > 1) return printf("-1\n"), void();
	if(a + b + 2 > n) return printf("-1\n"), void();
	if(a == b) {
		for(int i = 1; i <= a; i++) printf("%d %d ", i, n - i + 1);
		for(int i = a + 1; i <= n - a; i++) printf("%d ", i);
		printf("\n");
	}
	else if(a == b + 1) {
		for(int i = 1; i <= a; i++) printf("%d %d ", i, n - i + 1);
		for(int i = n - a; i >= a + 1; i--) printf("%d ", i);
		printf("\n");
	}
	else { 
		for(int i = 1; i <= b; i++) printf("%d %d ", n - i + 1, i);
		for(int i = b + 1; i <= n - b; i++) printf("%d ", i);
		printf("\n");
	}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}