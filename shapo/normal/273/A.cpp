#include <cstdio>
#include <iostream>

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define maxn 100500

int mx[maxn];
int n;
ll ans = 0LL;

int main() {
	scanf("%d", &n), mx[0] = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%d", mx + i);
	int m, curw, curh;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &curw, &curh);
		ans = max(ans, ll(mx[curw])) + curh;
		printf(LLD "\n", ans - curh);
	}
	return 0;
}