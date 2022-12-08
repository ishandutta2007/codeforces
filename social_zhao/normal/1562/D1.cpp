#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
char s[N];
int sum[N], n, q;

void solve() {
	n = get(), q = get();
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) {
		int now = s[i] == '+'? 1 : -1;
		if(i & 1) now *= -1;
		sum[i] = sum[i - 1] + now;
	}
	for(int i = 1; i <= q; i++) {
		int l = get(), r = get();
		if((r - l + 1) & 1) { printf("1\n"); continue; }
		int now = sum[r] - sum[l - 1];
		if(!now) printf("0\n");
		else printf("2\n");
	}
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}