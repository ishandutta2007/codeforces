#include <cstdio>
#include <iostream>
using namespace std;
const int N = 300000;

int t, n;
long long a[N], b[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld%lld", &n, a, b);
		long long ans = 0, mina = 0x7fffffffffffffff;
		for(int i = 1; i < n; i++){
			scanf("%lld%lld", a + i, b + i);
			ans += max(0ll, a[i] - b[i - 1]);
			a[i] = min(a[i], b[i - 1]);
			mina = min(mina, a[i]);
		}
		ans += max(0ll, a[0] - b[n - 1]);
		a[0] = min(a[0], b[n - 1]);
		printf("%lld\n", ans + min(mina, a[0]));
	}
	return 0;
}