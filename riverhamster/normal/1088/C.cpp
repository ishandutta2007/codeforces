#include <cstdio>
#include <algorithm>
using namespace std;

long long a[2005];
int val[2005];

int main(){
	// freopen("cf1088c.in", "r", stdin);
	// freopen("cf1088c.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%lld", &a[i]);
	int add = 0, mod = n;
	for(int i=n; i>=1; i--){
		a[i] %= mod;
		if((a[i] + add) % mod <= i - 1) val[i] = (i - 1) - (a[i] + add) % mod;
		else val[i] = mod + (i - 1) - (a[i] + add) % mod;
		// printf("add = %d val[%d] = %d\n", add, i, val[i]);
		add = (add + val[i]) % mod;
	}
	printf("%d\n", n+1);
	for(int i=n; i>=1; i--)
		printf("1 %d %d\n", i, val[i]);
	printf("2 %d %d\n", n, n);
	return 0;
}