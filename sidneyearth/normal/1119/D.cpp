#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100100;
long long a[maxn], s[maxn];
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &s[i]);
	sort(s + 1, s + 1 + n);
	for(int i = 1; i < n; ++i)
		s[i] = s[i + 1] - s[i];
	sort(s + 1, s + n);
	for(int i = 1; i < n; ++i)
		a[i] = s[i] + a[i-1];
	int q; scanf("%d", &q);
	for(int i = 1; i <= q; ++i){
		long long l, r;
		scanf("%lld%lld", &l, &r);
		long long dis = r - l + 1;
		long long pos = lower_bound(s + 1, s + n, dis) - s;
		printf("%lld\n", a[pos - 1] + (n - pos + 1ll) * dis);
	}
	return 0;
}