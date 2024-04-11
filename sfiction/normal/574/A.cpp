#include <cstdio>

const int MAXN = 1E2 + 10;

int n;
int a[MAXN];

bool check(int x){
	int limit = a[0] + x, cnt = 0;
	for (int i = 1; i < n; ++i)
		if (a[i] >= limit)
			cnt += a[i] - limit + 1;
	return x >= cnt;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int high = 1E5 + 1, low = 0, mid;
	while (high > low){
		mid = high + low >> 1;
		if (check(mid))
			high = mid;
		else
			low = mid + 1;
	}
	printf("%d", low);
	return 0;
}