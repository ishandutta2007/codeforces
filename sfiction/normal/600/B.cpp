#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E5 + 10;

int a[MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int t, i = 0; i < m; ++i){
		scanf("%d", &t);
		printf("%d%c", upper_bound(a, a + n, t) - a, "\n "[i < m - 1]);
	}
	return 0;
}