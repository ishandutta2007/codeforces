#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1E5 + 10;

int fa[MAXN], cnt[MAXN];
double ans[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
		scanf("%d", &fa[i]);
	for (int i = n; i >= 1; --i)
		cnt[fa[i]] += ++cnt[i];
	ans[1] = 1.0;
	for (int i = 2; i <= n; ++i)
		ans[i] = ans[fa[i]] + 1.0 + (cnt[fa[i]] - 1 - cnt[i]) / 2.0;
	for (int i = 1; i <= n; ++i)
		printf("%.1f%c", ans[i], "\n "[i < n]);
	return 0;
}