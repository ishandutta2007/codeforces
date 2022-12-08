#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

void solve() {
	int n = get();
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= i; j++) printf("(");
		for(int j = 1; j <= n - i; j++) printf("()");
		for(int j = 1; j <= i; j++) printf(")");
		printf("\n");
	}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}