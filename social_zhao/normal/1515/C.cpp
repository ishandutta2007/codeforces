#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, m, x, bel[N];
pair<int, int> a[N];
priority_queue< pair<int, int> > q;

void solve() {
	n = get(), m = get(), x = get();
	for(int i = 1; i <= n; i++) a[i].first = get(), a[i].second = i;
	for(int i = 1; i <= m; i++) q.push(make_pair(0, i));
	sort(a + 1, a + 1 + n, [](pair<int, int> x, pair<int, int> y) { return x > y; });
	for(int i = 1; i <= n; i++) {
		pair<int, int> now = q.top(); q.pop();
		now.first -= a[i].first, bel[a[i].second] = now.second;
		q.push(now);
	}
	int mn = 0x3f3f3f3f, mx = 0;
	while(q.size()) mn = min(mn, -q.top().first), mx = max(mx, -q.top().first), q.pop();
	if(mx - mn <= x) {
		printf("YES\n");
		for(int i = 1; i <= n; i++) printf("%d ", bel[i]); printf("\n");
	}
	else printf("NO\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}