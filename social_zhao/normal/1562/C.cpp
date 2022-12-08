#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n;
char s[N];

void solve() {
	n = get();
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') continue;
		if(i <= (n / 2)) printf("%d %d %d %d\n", i, n, i + 1, n);
		else printf("%d %d %d %d\n", 1, i, 1, i - 1);
		return;
	}
	printf("%d %d %d %d\n", 1, n - 1, 2, n);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
2
5
11011
8
11101111
*/