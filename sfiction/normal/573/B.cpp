#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10;

int a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		a[i] = min(a[i], a[i - 1] + 1);
	int ans = 0;
	for (int i = n; i > 0; --i){
		a[i] = min(a[i], a[i + 1] + 1);
		ans = max(ans, a[i]);
	}
	printf("%d\n", ans);
	return 0;
}