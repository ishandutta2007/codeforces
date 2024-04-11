#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 101;

int t, n;
long long a[N], s[N], h;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld", &n, &h);
		for(int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		a[n] = 0x7fffffffffffffff;
		for(int i = n - 1; i; i--)
			a[i] -= a[i - 1];
		sort(a + 1, a + n);
		for(int i = 1; i < n; i++)
			s[i] = s[i - 1] + a[i];
		int i;
		for(i = 1; i < n && s[i - 1] + (n - i + 1) * a[i] < h; i++);
		printf("%lld\n", (h - s[i - 1] - 1) / (n - i + 1) + 1);
	}
	return 0;
}