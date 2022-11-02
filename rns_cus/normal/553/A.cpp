#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <set>
#include <queue>
#include <map>
#include <math.h>
#include <vector>
#include <ctype.h>
#include <string.h>
#include <string>
using namespace std;
typedef long long ll;
const int M = 300010;
const int mod = 1000000007;
#define all(it,a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int n, a[M], f[1010][1010];

int main() {
	scanf("%d", &n);
	f[0][0] = f[0][1] = 1;
	for (int i = 1; i <= 1000; i++) {
		f[i][0] = f[i][i] = 1;
		for(int j = 1; j < i; j++) {
            f[i][j] = (f[i-1][j] + f[i-1][j-1]) % mod;
		}
	}
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	ll ans = 1;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans * f[a[i]+tot-1][a[i]-1]) % mod;
		tot += a[i];
	}
	printf("%I64d\n", ans);
	return 0;
}