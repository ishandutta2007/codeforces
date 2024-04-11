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

int vis[128];
char s[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; ++i)
		vis[s[i]] = true;
	int m = accumulate(vis, vis + 128, 0);
	memset(vis, 0, sizeof(vis));
	int cnt = 0, ans = n;
	for (int i = 0, j = 0; i < n; ++i){
		for (; j < n && cnt < m; ++j)
			cnt += !(vis[s[j]]++);
		if (cnt < m)
			break;
		ans = min(ans, j - i);
		cnt -= !(--vis[s[i]]);
	}
	printf("%d\n", ans);
	return 0;
}