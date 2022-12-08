#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, pa[N], pb[N], cnt, p[N], col[N], vis[N];
int shit[2], d[2], tmp, top;
pair<int, int> bin[N];

bool cmp(pair<int, int> a, pair<int, int> b) {
	int lena = a.first, lenb = b.first;
	int delta = -lena * (lenb / 2) + lenb * (lena / 2);
	return delta > 0;
}

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) pa[i] = get();
	for(int i = 1; i <= n; i++) pb[i] = get();
	for(int i = 1; i <= n; i++) p[pa[i]] = pb[i], col[i] = 0, vis[i] = 0;
	shit[0] = 1, shit[1] = n, d[0] = 1, d[1] = -1, tmp = 0, top = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		int now = i, cnt = 0;
		while(!vis[now]) vis[now] = 1, ++cnt, now = p[now];
		bin[++top] = make_pair(cnt, now);
	}
	sort(bin + 1, bin + 1 + top, cmp);
	
	for(int i = 1; i <= top; i++) {
		int now = bin[i].second;
		for(int j = 1; j <= bin[i].first / 2 * 2; j++) {
			col[now] = shit[tmp], shit[tmp] += d[tmp];
			tmp ^= 1;
			now = p[now];
		}
	}
	for(int i = 1; i <= n; i++) if(!col[i]) col[i] = shit[0], shit[0] += d[0];
	
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += abs(col[pa[i]] - col[pb[i]]);
	cout << ans << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}