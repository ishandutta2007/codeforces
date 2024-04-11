#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N = 5e5 + 10;

long long sum[N], c[N];
vector<int> g[N];
map<ull, long long> Rmap[N];

long long gcd(long long x, long long y) {
	if(y == 0)return x;
	return gcd(y, x % y);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &c[i]);
			sum[i] = 0;
			g[i].clear();
			Rmap[i].clear();
		}
		for(int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			sum[x] += c[y];
			g[y].push_back(x);
		}
		long long ans = sum[1];
		for(int i = 2; i <= n; i++) {
			ans = gcd(ans, sum[i]);
		}
		for(int i = 1; i <= n; i++) {
			sort(g[i].begin(), g[i].end());
			ull nowhash = 0;
			for(int j = 0; j < g[i].size(); j++) {
				nowhash = nowhash * 2333333 + g[i][j];
			}
			Rmap[g[i].size()][nowhash] += c[i];
		}
		for(int i = 1; i <= n; i++) {
			if(Rmap[i].size() == 0)continue;
			for(map<ull, long long>::iterator it = Rmap[i].begin(); it != Rmap[i].end(); it++) {
				ans = gcd(ans, it -> second);
			}
		}
		printf("%lld\n", ans);
	}
}