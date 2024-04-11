#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E5 + 10;

int a[MAXN], b[MAXN];
int mark[MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", b + i), a[i] = (100 - b[i] % 100) % 100;

	priority_queue<PII, vector<PII>, greater<PII>> Q;
	ll ans = 0;
	for (int i = 1; i <= n; ++i){
		int cost;
		scanf("%d", &cost);
		int t = a[i] * cost;
		m += a[i];
		ans += t;
		if (m >= 100){
			m -= 100;
			Q.emplace(t, i);
		}
		else if (!Q.empty() && t > Q.top().st){
			Q.pop();
			Q.emplace(t, i);
		}
	}
	for (; !Q.empty(); Q.pop())
		ans -= Q.top().st, mark[Q.top().nd] = true;
	printf("%lld\n", ans);
	for (int i = 1; i <= n; ++i)
		if (mark[i])
			printf("%d %d\n", b[i] / 100, b[i] % 100);
		else
			printf("%d 0\n", (b[i] + 99) / 100);
	return 0;
}