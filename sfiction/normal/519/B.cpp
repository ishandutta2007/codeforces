/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 519B
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 100;

int n;
int a[MAXN], b[MAXN], c[MAXN];

int main(){
	scanf("%d", &n);
	for (int i=0;i<n;++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i=0;i<n-1;++i)
		scanf("%d", &b[i]);
	sort(b, b + n - 1);
	for (int i=0;i<n-2;++i)
		scanf("%d", &c[i]);
	sort(c, c + n - 2);

	int i;
	for (i=0;i<n-1 && a[i] == b[i];++i);
	printf("%d\n", a[i]);
	for (i=0;i<n-2 && b[i] == c[i];++i);
	printf("%d\n", b[i]);
	return 0;
}