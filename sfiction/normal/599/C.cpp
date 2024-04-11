#include <climits>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10;

int a[MAXN], b[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		b[i] = max(a[i], b[i - 1]);
	}
	int val = INT_MAX, ans = 0;
	for (int i = n; i > 0; --i){
		val = min(val, a[i]);
		if (val >= b[i - 1])
			++ans, val = INT_MAX;
	}
	printf("%d\n", ans);
	return 0;
}