#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 200100;
int a[maxn];
int main(){
	int n, s; scanf("%d%d", &n, &s);
	int m = (n + 1) / 2;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	long long ans = 0;
	for(int i = 1; i < m; i++)
		if(a[i] > s) ans += a[i] - s;
	ans += abs(a[m] - s);
	for(int i = m + 1; i <= n; i++)
		if(a[i] < s) ans += s - a[i];
	printf("%I64d\n", ans);
	return 0;
}