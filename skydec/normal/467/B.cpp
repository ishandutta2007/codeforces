#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1100
using namespace std;

int num[MAXN],cnt;
int ans = 0;int n,m,k;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
		scanf("%d", &num[i]);
	scanf("%d", &cnt);
	for (int i = 0; i < m; i++) {
		int cur = 0;
		for (int j = 0; j < n; j++)
			if (((1<<j)&num[i])!=((1<<j)&cnt))
				cur++;
		if (cur <= k)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}