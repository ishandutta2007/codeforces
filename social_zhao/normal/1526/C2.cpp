#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n, sum = 0, ans;
priority_queue<int> q;

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) {
		int x = get();
		if(sum + x >= 0) q.push(-x), sum += x, ans++;
		else {
			if(q.size() && sum + q.top() + x >= sum) sum += q.top() + x, q.pop(), q.push(-x);
		}
	}
	printf("%lld\n", q.size());
	return 0;
}