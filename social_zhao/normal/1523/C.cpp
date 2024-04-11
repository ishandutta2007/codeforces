#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e3 + 5;
int n, st[N], top;

void print() {
	for(int i = 1; i < top; i++) printf("%d.", st[i]);
	printf("%d\n", st[top]);
}

void solve() {
	n = get(), top = 0;
	for(int i = 1; i <= n; i++) {
		int now = get();
		if(now == 1) st[++top] = now;
		else { while(st[top] != now - 1) top--; ++st[top]; }
		print();
	}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}