#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;

int n;
int a[MAXN];
ll s[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	double ans = -1;
	int ansi, ansl;
	for (int i = 1; i <= n; ++i){
		int high = min(i - 1, n - i) + 1, low = 1, mid;
		ll sum = s[i] + s[n];
		while (low < high){
			mid = high + low >> 1;
			// a[i-mid..i], a[n-mid+1..n], i>mid,n-i+1>mid
			//ll l = s[i] - s[i - mid - 1], r = s[n] - s[n - mid];
			if ((sum - s[i - mid - 1] - s[n - mid] << 1) < (a[i - mid] + a[n - mid + 1]) * (mid << 1 | 1ll))
				low = mid + 1;
			else
				high = mid;
		}
		--low;
		double t = (sum - s[i - low - 1] - s[n - low]) / (double)(low << 1 | 1) - a[i];
		if (ans < t){
			ans = t;
			ansi = i, ansl = low;
		}
	}
	printf("%d\n", ansl << 1 | 1);
	for (int i = ansi - ansl; i < ansi; ++i)
		printf("%d ", a[i]);
	for (int i = n - ansl + 1; i <= n; ++i)
		printf("%d ", a[i]);
	printf("%d\n", a[ansi]);
	return 0;
}