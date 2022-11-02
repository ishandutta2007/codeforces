#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], du[N], vis[N];
vector<int> g[N];
priority_queue<pair<int, int> > q;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		long long ans = 0;
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]), ans += a[i], g[i].clear(), du[i] = vis[i] = 0;
		for(int i = 1; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
			du[x]++, du[y]++;
		}
		while(q.size())q.pop();
		for(int i = 1; i <= n; i++)
			if(du[i] > 1)
				q.push(make_pair(a[i], i));
		printf("%lld", ans);
		for(int i = 1; i < n - 1; i++) {
			pair<int, int> tmp = q.top();
			int v = tmp.first, x = tmp.second;
			ans += v;
			du[x]--;
			if(du[x] == 1) {
				q.pop();
			}
			printf(" %lld", ans);
		}
		puts("");
	}
}