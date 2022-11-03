#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5E5 + 10;

int a[MAXN];
char s[MAXN];

int main(){
	int n;
	long long sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	scanf("%s", s);
	for (int i = 0; i < n; ++i)
		if (s[i] == 'B')
			sum += a[i];
	long long ans = sum, t = sum;
	for (int i = 0; i < n; ++i)
		ans = max(ans, sum += s[i] == 'A' ? a[i] : -a[i]);
	sum = t;
	for (int i = n - 1; i >= 0; --i)
		ans = max(ans, sum += s[i] == 'A' ? a[i] : -a[i]);
	printf("%I64d\n", ans);
	return 0;
}