#include <cstdio>
using namespace std;
const int MAXN = 250001;

int n, p, fac[MAXN] = {1}, ans;

int main(){
	scanf("%d%d", &n, &p);
	for(int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % p;
	for(int i = 1; i <= n; i++)
		ans = (ans + 1ll * fac[n - i] * fac[i] % p * (n - i + 1) % p * (n - i + 1) % p) % p;
	printf("%d", ans);
	return 0;
}