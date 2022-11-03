#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;

int n;
int a[MAXN];
ll s[MAXN], s2[MAXN];

int r;
ll x[MAXN], y[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
		s2[i] = s2[i - 1] + a[i] * (ll)i;
	}
	
	r = 0;
	x[0] = 0, y[0] = 0;
	ll ans = 0;
	for (int i = 1; i <= n; ++i){
		int high = r, low = 0, mid;
		while (low < high){
			mid = high + low >> 1;
			if ((y[mid + 1] - y[mid]) / (double)(x[mid + 1] - x[mid]) > s[i])
				low = mid + 1;
			else
				high = mid;
		}
		ans = max(ans, y[low] - x[low] * s[i] + s2[i]);

		ll tx = i, ty = s[i] * i - s2[i];
		for (; 0 <= r && (y[r] - y[r - 1]) / (double)(x[r] - x[r - 1]) <= (ty - y[r]) / (double)(tx - x[r]); --r);
		x[++r] = tx, y[r] = ty;
	}
	printf("%I64d\n", ans);
	return 0;
}