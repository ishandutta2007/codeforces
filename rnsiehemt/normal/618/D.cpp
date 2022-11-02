#include <bits/stdc++.h>
typedef long long ll;

const int MaxN = 200005;

int N, degree[MaxN], k;
ll x, y;
std::vector<int> e[MaxN];

int go(int i, int p) {
	int c = 0;
	for (int j : e[i]) if (j != p) c += go(j, i);
	if (c == 0) return 1;
	else if (c == 1) { k++; return 1; }
	else { k += 2; return 0; }
}

int main()
{
	scanf("%d%lld%lld", &N, &x, &y);
	for (int i = 0; i < N-1; i++) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		e[u].push_back(v); e[v].push_back(u);
		degree[u]++; degree[v]++;
	}
	if (x >= y) {
		for (int i = 0; i < N; i++) if (degree[i] == N-1) {
			printf("%lld\n", (N-2)*y + x);
			return 0;
		}
		printf("%lld\n", (N-1)*y);
	} else {
		go(0, -1);
		printf("%lld\n", k*x + (N-1-k)*y);
	}
}