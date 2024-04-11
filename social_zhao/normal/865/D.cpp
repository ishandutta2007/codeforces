#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n, ans = 0;
priority_queue<int> q;

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) {
		int a = get();
		if(q.size() && a > -q.top()) ans += a + q.top(), q.pop(), q.push(-a);
		q.push(-a);
	}
	printf("%lld\n", ans);
	return 0;
}