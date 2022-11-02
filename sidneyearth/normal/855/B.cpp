#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int main(){
	ll n, p, q, r, f[3];
	scanf("%I64d%I64d%I64d%I64d", &n, &p, &q, &r);
	f[0] = f[1] = f[2] = -INF;
	for(int i = 1; i <= n; i++){
		ll a; scanf("%I64d", &a);
		f[0] = max(f[0], a * p);
		f[1] = max(f[1], f[0] + a * q);
		f[2] = max(f[2], f[1] + a * r);
	}
	printf("%I64d\n", f[2]);
	return 0;
}