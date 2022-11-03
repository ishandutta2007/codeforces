#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E5 + 10;

int n, m, K;
int a[MAXN], b[MAXN];
int p[MAXN];

int main(){
	scanf("%d%d%d", &n, &m, &K);
	a[0] = 1, b[0] = 0;
	for (int i = 1; i <= m; ++i){
		scanf("%d", a + i);
		b[i] = b[i - 1] + a[i - 1];
	}
	a[m + 1] = b[m + 1] = 0;
	K -= a[m];
	for (int i = 1; i <= m; ++i){
		if (a[i - 1] > a[i])
			K -= a[i - 1] - a[i];
		for (int j = 1; j <= a[i]; ++j)
			p[b[i] + j] = min(b[i], b[i - 1] + j);
	}
	for (int i = 1; K > 0 && i <= m; ++i){
		for (int j = 1; K > 0 && j < a[i - 1] && j < a[i]; ++j){
			p[b[i] + j] = b[i - 1] + min(a[i - 1], a[i]);
			--K;
		}
	}
	if (K != 0)
		puts("-1");
	else{
		printf("%d\n", n);
		for (int i = 2; i <= n; ++i)
			printf("%d %d\n", i, p[i]);
	}
	return 0;
}