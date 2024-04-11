#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 10;
 
vector<int> a[N];
int ans[N], k[N], cnt[N];
 
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int lim = (m + 1) / 2;
		for(int i = 1; i <= n; i++)
			cnt[i] = 0;
		for(int i = 1; i <= m; i++)
			ans[i] = 0, a[i].clear();
		for(int i = 1; i <= m; i++) {
			scanf("%d", &k[i]);
			for(int j = 1; j <= k[i]; j++) {
				int x;
				scanf("%d", &x);
				a[i].push_back(x);
				cnt[x]++;
			}
		}
		int mxid = 0;
		for(int i = 1; i <= n; i++)
			if(cnt[i] > cnt[mxid])
				mxid = i;
		if(cnt[mxid] <= lim) {
			puts("YES");
			for(int i = 1; i < m; i++)
				printf("%d ", a[i][0]);
			printf("%d\n", a[m][0]);
			continue;
		}
		int tot = 0;
		for(int i = 1; i <= m; i++)
			if(k[i] == 1 && a[i][0] == mxid)
				ans[i] = mxid, tot++;
		if(tot > lim) {
			puts("NO");
			continue;
		}
		for(int i = 1; i <= m; i++) {
			if(ans[i])continue;
			if(tot < lim) {
				for(int j = 0; j < k[i]; j++)
					if(a[i][j] == mxid) {
						ans[i] = a[i][j];
						tot++;
						break;
					}
			}
			else {
				for(int j = 0; j < k[i]; j++)
					if(a[i][j] != mxid) {
						ans[i] = a[i][j];
						break;
					}
			}
			if(!ans[i])ans[i] = a[i][0];
		}
		puts("YES");
		for(int i = 1; i < m; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[m]);
	}
}