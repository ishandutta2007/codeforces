#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

void solve() {
	int l = get(), r = get();
	int mid = r / 2 + 1;
	if(l <= mid && mid <= r) printf("%d\n", r % mid);
	else printf("%d\n", r % l);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}