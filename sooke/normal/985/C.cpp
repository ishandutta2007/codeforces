#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define Maxn 100005

#define lol long long

int n, m, ans, cnt;
lol k, sum, a[Maxn];
bool used[Maxn];

int main() {
	scanf("%d%d%lld", &n, &m, &k);
	for (int i = 1; i <= n * m; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n * m + 1);
	if (n == 1) {
		printf("%lld\n", a[1]);
		return 0;
	}
	for (int l = n, r = n * m - m + 1, mid; l <= r; ) {
		mid = l + r >> 1;
		if (a[mid] - a[1] <= k) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	if (ans == 0) {
		printf("0\n");
	} else {
		sum = a[1] + a[ans];
		used[1] = used[ans] = true;
		for (int i = n * m; i >= 1; i--) {
			if (used[i]) {
				cnt -= m - 1;
			} else {
				cnt++;
				if (cnt >= m && i <= ans) {
					cnt -= m;
					sum += a[i];
				}
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}

// By Sooke.
// CF985C Liebig's Barrels.