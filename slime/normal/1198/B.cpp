#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int n;
int a[maxn];
int t[maxn], r[maxn], s[maxn]; 
int ans[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int q;
	scanf("%d", &q);
	for (int j = 1; j <= q; j++) {
		scanf("%d", &t[j]);
		if (t[j] == 1) scanf("%d%d", &r[j], &s[j]);
		else scanf("%d", &r[j]);
	}
	memset(ans, -1, sizeof(ans));
	int mx = 0;
	for (int j = q; j >= 1; j--) {
		if (t[j] == 1) {
			if (ans[r[j]] != -1) continue;
			ans[r[j]] = max(mx, s[j]);
		}
		else mx = max(mx, r[j]);
	}
	for (int j = 1; j <= n; j++) {
		if (ans[j] == -1) ans[j] = max(a[j], mx);
		printf("%d ", ans[j]);
	}
	return 0;
}