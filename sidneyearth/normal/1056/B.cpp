#include <stdio.h>
using namespace std;
int f[1010];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
		f[(i * i) % m] += n / m + (n % m >= i);
	long long ans = (long long)f[0] * f[0];
	for(int i = 1, j = m - 1; i < m; i++, j--)
		ans += (long long)f[i] * f[j];
	printf("%I64d\n", ans);
	return 0;
}