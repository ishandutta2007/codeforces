#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E3 + 10;

int a[MAXN], b[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		int A = 0, B = 0;
		for (int j = i; j <= n; ++j){
			ans = max(ans, (A |= a[j]) + (B |= b[j]));
		}
	}
	printf("%d\n", ans);
	return 0;
}