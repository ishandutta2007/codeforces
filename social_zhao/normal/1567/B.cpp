#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
int sum[N];

void init(int n) {
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] ^ i;
}

void solve() {
	int a = get(), b = get(), ans = a;
	int now = b ^ sum[a - 1];
	if(now == a) ans += 2;
	else if(now) ans++;
	printf("%d\n", ans);
}

int main() {
	init(300000);
	int T = get();
	while(T--) solve();
	return 0;
}