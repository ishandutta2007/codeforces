#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

void solve() {
	int x = get(), y = get();
	if(x == y) return printf("%d\n", x), void();
	else if(x > y) return printf("%d\n", x + y), void();
	else if(x > y / 2) return printf("%d\n", (x + y) / 2), void();
	else return printf("%d\n", y - (y % x) / 2), void();
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}