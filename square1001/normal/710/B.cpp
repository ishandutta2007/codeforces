#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[300009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	printf("%d\n", a[(n - 1) / 2]);
	return 0;
}