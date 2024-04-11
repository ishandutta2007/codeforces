#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;
const int INF = 1E9 + 5;

int n, K, b, c;
int a[MAXN];
ll cost[5];
priority_queue<ll> Q[5];

void update(int i, int x){
	ll t = INF + i - x;
	t = t / 5 * b + t % 5 * c;
	cost[i] += t;
	Q[i].push(t);
	if (Q[i].size() > K){
		cost[i] -= Q[i].top();
		Q[i].pop();
	}
}

ll query(int i, int x){
	return cost[i] - (INF + i - x) / 5ll * b * K;
}

int main(){
	scanf("%d%d%d%d", &n, &K, &b, &c);
	b = min(b, 5 * c);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	ll ans = 1ll << 62;
	for (int j = 0; j < 5; ++j){
		int t = (a[K - 1] + j + INF) % 5;
		for (int i = 0; i < K; ++i)
			update(t, a[i]);
		ans = min(ans, query(t, a[K - 1] + j));
	}
	for (int i = K; i < n; ++i)
		for (int j = 0; j < 5; ++j){
			int t = (a[i] + j + INF) % 5;
			update(t, a[i]);
			ans = min(ans, query(t, a[i] + j));
		}
	printf("%I64d\n", ans);

	return 0;
}