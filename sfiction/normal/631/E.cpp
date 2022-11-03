#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;

int n;
ll a[MAXN];
ll sum[MAXN];

int r, que[MAXN];

ll ans, c0;

double slope(int i, int j){
	return (sum[i] - sum[j]) / (i - j);
}

void solve1(){
	r = 0;
	que[0] = n;
	for (int i = n - 1; i >= 1; --i){
		int high = r, low = 0, mid;
		while (low < high){
			mid = high + low >> 1;
			if (sum[que[mid]] - a[i] * (que[mid] - que[mid + 1]) > sum[que[mid + 1]])
				low = mid + 1;
			else
				high = mid;
		}
		ans = max(ans, c0 - a[i] * i + sum[i] + a[i] * que[low] - sum[que[low]]);

		for (; 0 < r && sum[i] * (que[r - 1] - i) + (sum[que[r - 1]] - sum[i]) * (que[r] - i) <= sum[que[r]] * (que[r - 1] - i); --r);
		que[++r] = i;
	}
}

void solve2(){
	r = 0;
	que[0] = 1;
	for (int i = 2; i <= n; ++i){
		int high = r, low = 0, mid;
		while (low < high){
			mid = high + low >> 1;
			if (sum[que[mid] - 1] + a[i] * (que[mid + 1] - que[mid]) > sum[que[mid + 1] - 1])
				low = mid + 1;
			else
				high = mid;
		}
		ans = max(ans, c0 - a[i] * i + sum[i - 1] + a[i] * que[low] - sum[que[low] - 1]);

		for (; 0 < r && sum[i - 1] * (que[r - 1] - i) + (sum[que[r - 1] - 1] - sum[i - 1]) * (que[r] - i) >= sum[que[r] - 1] * (que[r - 1] - i); --r);
		que[++r] = i;
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%I64d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		c0 += a[i] * i;
	}
	ans = c0;
	solve1();
	solve2();
	printf("%I64d\n", ans);
	return 0;
}