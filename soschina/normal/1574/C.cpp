#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;

int n, m;
long long a[N], sum, x, y;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		sum += a[i];
	}
	sort(a + 1, a + 1 + n);
	scanf("%d", &m);
	while(m--){
		scanf("%lld%lld", &x, &y);
		long long *ptr = upper_bound(a + 1, a + 1 + n, x) - 1;
		if(ptr == a) printf("%lld\n", max(0ll, y + a[1] - sum));
		else if(ptr == a + n) printf("%lld\n", max(0ll, y + *ptr - sum) + x - *ptr);
		else printf("%lld\n", min(max(0ll, y + *ptr - sum) + x - *ptr, max(0ll, y + *(ptr + 1) - sum)));
	}
	return 0;
}