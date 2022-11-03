#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;

ll a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
	}
	ll val = a[n];
	for (int i = n - 1; i > 1; --i)
		val = max(val, a[i] - val);
	printf("%lld\n", val);
	return 0;
}