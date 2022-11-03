#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E2 + 10;

int n, m;
int a[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), a[i] = -a[i];
	sort(a, a + n);
	int ans = 0;
	for (; m > 0; m += a[ans++]);
	printf("%d\n", ans);
	return 0;
}