#include <bits/stdc++.h>

using namespace std;

const int N = 110;

vector<int> g[N];
int vis[N], x[N], y[N], q[N];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &x[i], &y[i]);
			g[i].clear();
			vis[i] = 0;
		}
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
		int flag = -1;
		for(int i = 1; i <= n; i++)
			if(g[i].size() == n - 1)flag = 1;
		printf("%d\n", flag);
	}
}