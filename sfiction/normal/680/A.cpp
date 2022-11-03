#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E2 + 10;

int a[MAXN];

int main(){
	int n = 5, sum = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for (int j = 0, i = 0; i < n; i = j){
		for (j = i + 1; j < n && a[j] == a[i]; ++j);
		if (j - i >= 2)
			ans = max(ans, a[i] * min(3, j - i));
	}
	printf("%d\n", sum - ans);
	return 0;
}