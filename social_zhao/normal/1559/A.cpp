#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

void solve() {
	int n = get(), ans = get();
	for(int i = 2; i <= n; i++) ans &= get();
	printf("%d\n", ans);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}