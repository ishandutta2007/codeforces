#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10;

int a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		a[t] = i;
	}
	int ans = 1, len = 1;
	for (int i = 2; i <= n; ++i)
		if (a[i - 1] < a[i])
			ans = max(ans, ++len);
		else
			len = 1;
	printf("%d\n", n - ans);
	return 0;
}