/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 140D
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n;
int a[MAXN];

int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);

	int solve = 0, penalty = 0;
	a[0] = 10;
	for (int i=1;i<=n;++i){
		a[i] += a[i - 1];
		if (a[i] > 720)
			break;
		++solve;
		if (a[i] > 360)
			penalty += a[i] - 360;
	}

	printf("%d %d", solve, penalty);

	return 0;
}