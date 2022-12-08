#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, a[N];

int solve(int x) {
	int lft = x * x, rht = x * x + x, nowl = max(0ll, x * x - a[1]), nowr = x * x + x - a[1];
	int now = 0;
	while(now < n) {
		if(nowl > nowr) return -1;
		++now;
		int blo = sqrt(a[now] + nowr);
		int l = now, r = n, ans = l;
		while(l <= r) {
			int mid = ((l + r) >> 1);
			if((int)sqrt(a[mid] + nowr) == blo) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		nowl = max(nowl, (blo * blo) - a[now]);
		nowr = min(nowr, (blo * blo + blo) - a[ans]);
		now = ans;
	}
	if(nowl > nowr) return -1;
	return nowl;
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= a[n]; i++) {
		int lft = i * i, rht = i * i + i;
		int res = solve(i);
		if(res != -1) { printf("%lld\n", res); break; }
	}
	return 0;
}