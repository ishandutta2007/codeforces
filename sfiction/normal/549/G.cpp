/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 549G
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E5 + 100;

int a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;++i){
		scanf("%d", &a[i]);
		a[i] += i;
	}
	sort(a, a + n);
	if (unique(a, a + n) != a + n)
		puts(":(");
	else{
		printf("%d", a[0]);
		for (int i=1;i<n;++i)
			printf(" %d", a[i] - i);
	}
	return 0;
}