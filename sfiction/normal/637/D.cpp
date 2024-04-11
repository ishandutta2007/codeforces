#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E5 + 10;

int a[MAXN];

int main(){
	int n, m, S, D;
	scanf("%d%d%d%d", &n, &m, &D, &S);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	a[0] = -1;
	if (a[1] - 1 < D){
		puts("IMPOSSIBLE");
		return 0;
	}
	int last = 0;
	for (int i = 1; i < n; ++i){
		if (a[last + 1] - 1 + S < a[i] + 1){
			puts("IMPOSSIBLE");
			return 0;
		}
		if (D <= a[i + 1] - a[i] - 2)
			last = i;
	}
	if (a[last + 1] - 1 + S < a[n] + 1){
		puts("IMPOSSIBLE");
		return 0;
	}
	
	last = 0;
	for (int i = 1; i < n; ++i){
		if (D <= a[i + 1] - a[i] - 2){
			printf("RUN %d\n", a[last + 1] - a[last] - 2);
			printf("JUMP %d\n", a[i] - a[last + 1] + 2);
			last = i;
		}
	}
	printf("RUN %d\n", a[last + 1] - a[last] - 2);
	printf("JUMP %d\n", a[n] - a[last + 1] + 2);
	if (a[n] + 1 != m)
		printf("RUN %d\n", m - a[n] - 1);
	return 0;
}