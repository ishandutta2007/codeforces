#include <stdio.h>
#include <algorithm>
#define N 100100

using namespace std;

int a[N], g[N];

int main() {
	int n, i, m, j;
	scanf("%d", &n);
	for (i=0; i<n; i++) scanf("%d", a+i);
	m=0;
	for (i=0; i<n; i++) {
		j=lower_bound(g, g+m, a[i])-g;
		m+=(j==m);
		g[j]=a[i];
	}
	printf("%d\n", m);
}