#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5;

int m[MAXN], w[MAXN];

int main(){
	int tot = 0;
	for (int i = 1; i <= MAXN; ++i)
		scanf("%d", &m[i]);
	for (int i = 1; i <= MAXN; ++i)
		scanf("%d", &w[i]);
	for (int i = 1; i <= MAXN; ++i)
		tot += max(150 * i, 500 * i - 2 * i * m[i] - 50 * w[i]);
	int hs, hu;
	scanf("%d%d", &hs, &hu);
	tot += hs * 100 - hu * 50;
	printf("%d\n", tot);
	return 0;
}