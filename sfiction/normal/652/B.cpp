#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E3 + 10;

int n, a[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		printf("%d%c", a[(i >> 1) + (i & 1 ? n + 1 >> 1 : 0)], "\n "[i < n - 1]);
	return 0;
}