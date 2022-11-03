#include <cstdio>

typedef long long ll;

const int MAXN = 1E5 + 10;

int n;
int a[MAXN], nex[MAXN];
int tail, que[MAXN];
ll dis[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
		scanf("%d", &a[i]);
	a[n] = n;

	que[tail = 0] = n;
	for (int i = n - 1; i > 0; --i){
		int low = 0, high = tail, mid;
		while (low < high){
			mid = low + high >> 1;
			if (que[mid] <= a[i])
				high = mid;
			else
				low = mid + 1;
		}
		nex[i] = que[low];

		for (; tail >= 0 && a[que[tail]] < a[i]; --tail);
		que[++tail] = i;
	}

	ll ans = 0;
	for (int i = n - 1; i > 0; --i)
		ans += dis[i] = dis[nex[i]] + (n - i) - (a[i] - nex[i]);
	printf("%I64d\n", ans);
	return 0;
}