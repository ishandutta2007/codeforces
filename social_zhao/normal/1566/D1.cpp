#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 305;
int n, a[N], b[N], len, pos[N], tot, vis[N], ans;
vector<int> bin[N];

void solve() {
	n = get(), n = get();
	for(int i = 1; i <= n; i++) a[i] = b[i] = get();
	sort(b + 1, b + 1 + n), len = unique(b + 1, b + 1 + n) - b - 1;
	for(int i = 1; i <= len; i++) bin[i].clear();
	for(int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + 1 + len, a[i]) - b;
	for(int i = n; i >= 1; i--) bin[a[i]].push_back(i), vis[i] = 0;
	tot = 0;
	for(int i = 1; i <= len; i++) 
		for(int j = 0; j < bin[i].size(); j++)
			pos[bin[i][j]] = ++tot;
	ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < pos[i]; j++) ans += vis[j];
		vis[pos[i]] = 1;
	}
	printf("%d\n", ans);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}