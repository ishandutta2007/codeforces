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
int n, m, k, p;
int a[N], h[N], now[N];
priority_queue<pair<int, int>> q;

int chk(int x) {
	while(q.size()) q.pop();
	for(int i = 1; i <= n; i++) if(x - a[i] * m < h[i]) q.push({ -x / a[i], i }), now[i] = x;
	for(int t = 1; t <= m && q.size(); t++) {
		for(int y = 1; y <= k && q.size(); y++) {
			pair<int, int> u = q.top(); q.pop();
			if(-u.first < t) return 0;
			int i = u.second;
			now[i] += p;
			if(now[i] - a[i] * m < h[i]) q.push({ -now[i] / a[i], i });
		}
	}
	return q.empty();
}

main() {
	n = get(), m = get(), k = get(), p = get();
	for(int i = 1; i <= n; i++) h[i] = get(), a[i] = get();
	int l = 0, r = 1e15, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(chk(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}