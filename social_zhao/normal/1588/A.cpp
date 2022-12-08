#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
int n, a[N], b[N];

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++) b[i] = get();
	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; i++) 
		if(a[i] == b[i] || a[i] + 1 == b[i]) continue;
		else return printf("NO\n"), void();
	printf("YES\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}