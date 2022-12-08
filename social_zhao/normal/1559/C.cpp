#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e4 + 5;
int n, a[N];

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	if(a[1] == 1) {
		printf("%d ", n + 1);
		for(int i = 1; i <= n; i++) printf("%d ", i);
		return;
	}
	if(a[n] == 0) {
		for(int i = 1; i <= n + 1; i++) printf("%d ", i);
		return;
	}
	for(int i = 1; i < n; i++) if(a[i] == 0 && a[i + 1] == 1) {
		for(int j = 1; j <= i; j++) printf("%d ", j);
		printf("%d ", n + 1);
		for(int j = i + 1; j <= n; j++) printf("%d ", j);
		return;
	}
	printf("-1");
}

int main() {
	int T = get();
	while(T--) solve(), printf("\n");
	return 0;
}