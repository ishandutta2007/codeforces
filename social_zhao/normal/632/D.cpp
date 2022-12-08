#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, m, a[N], tot, cnt[N], b[N], shit, f[N];

int main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++) if(a[i] <= m) cnt[a[i]]++, b[++tot] = a[i];
	sort(b + 1, b + 1 + tot); shit = unique(b + 1, b + 1 + tot) - b - 1;
	for(int i = 1; i <= shit; i++)
		for(int j = b[i]; j <= m; j += b[i])
			f[j] += cnt[b[i]];
	int maxn = -1, ans = 0;
	for(int i = 1; i <= m; i++)
		if(f[i] > maxn) maxn = f[i], ans = i;
	cout << ans << " " << maxn << endl;
	for(int i = 1; i <= n; i++) if(ans % a[i] == 0) cout << i << " ";
	return 0;
}