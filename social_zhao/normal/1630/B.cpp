#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 200005;
int n, k, a[N], cnt[N], sum[N];

void solve() {
	n = get(), k = get();
	for(int i = 1; i <= n; i++) a[i] = get(), cnt[i] = 0;
	for(int i = 1; i <= n; i++) ++cnt[a[i]];
	int der = 0 - n, x = 1, y = n;
	for(int i = 1, nowl = 1; i <= n; i++) {
		der += 2 * cnt[i];
		while(der - 2 * cnt[nowl] >= k) der -= 2 * cnt[nowl], nowl++;
		if(der >= k && i - nowl < y - x) x = nowl, y = i;
	}
	printf("%d %d\n", x, y);
	int lst = 1, sum = 0, ber = 0, tot = 0;
	for(int i = 1; i <= n; i++) {
		if(tot == k - 1) break;
		if(x <= a[i] && a[i] <= y) ++sum;
		else --sum;
		if(sum == ber + 1) ++tot, printf("%d %d\n", lst, i), lst = i + 1, ber = sum;
	}
	printf("%d %d\n", lst, n);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
11 3
5 5 5 1 5 5 1 5 5 5 1
*/