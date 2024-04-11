#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 2E5 + 10;

int n, s;
int a[MAXN];
int cnt[MAXN];

int main(){
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	int ans = 0, use = 0;
	if (a[s] != 0)
		++ans, a[s] = 0;
	swap(a[s], a[1]);

	int m = 0;
	for (int i = 2; i <= n; ++i)
		if (a[i] == 0)
			++ans, ++use;
		else{
			++cnt[a[i]];
			m = max(m, a[i]);
		}

	int mr;
	for (mr = 1; mr <= m && use >= 0; ++mr)
		if (cnt[mr] == 0){
			if (use == 0)
				break;
			++cnt[mr], --use;
		}

	if (mr > m){
		printf("%d\n", ans);
		return 0;
	}

	for (; mr < m; ){
		--cnt[m];
		++cnt[mr];
		++ans;

		for (; cnt[m] == 0; --m);
		for (; cnt[mr] != 0; ++mr);
	}
	printf("%d\n", ans);

	return 0;
}