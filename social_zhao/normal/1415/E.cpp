#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5;
int n, k, a[N]; 
priority_queue<int> q;

main() {
	n = get(), k = get();
	for(int i = 1; i <= k + 1; i++) q.push(0);
	for(int i = 1; i <= n; i++) a[i] = get();
	sort(a + 1, a + 1 + n, [](int x, int y) { return x > y; });
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int u = q.top(); q.pop();
		ans += u, q.push(u + a[i]);
	}
	cout << ans;
	return 0;
}