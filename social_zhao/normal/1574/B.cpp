#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

void solve() {
	int a = get(), b = get(), c = get(), m = get();
	int up = a - 1 + b - 1 + c - 1, dwn = max(0, max(a, max(b, c)) - 1 - (a + b + c - max(a, max(b, c))));
	if(dwn <= m && m <= up) printf("YES\n");
	else printf("NO\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}