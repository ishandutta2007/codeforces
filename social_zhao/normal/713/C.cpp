#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, k, b, a[N], bin[N];
priority_queue<int> q;

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get() - i + n;
	for(int i = 1; i <= n; i++) {
		while(k + q.size() > 0) 
			q.pop();
		k--, b += a[i], q.push(a[i]), q.push(a[i]);
	}
	int lstx = 0, lsty = b, nowk = k, ans = lsty, sze = q.size(); 
	while(q.size()) {
		int x = q.top();
		bin[q.size()] = x; 
		q.pop();
	}
	for(int i = 1; i <= sze; i++) {
		int x = bin[i];
		lsty += (x - lstx) * nowk, nowk++, lstx = x;
		ans = min(ans, lsty);
	}
	printf("%lld\n", ans);
	return 0;
}