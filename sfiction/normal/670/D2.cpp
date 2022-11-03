#include <cstdio>

typedef long long ll;

const int MAXN = 1E5 + 10;

int n, k;
int a[MAXN], b[MAXN];

bool check(ll x){
	ll s = k;
	for (int i = 0; 0 <= s && i < n; ++i)
		if (a[i] / b[i] < x)
			s -= b[i] * x - a[i];
	return 0 <= s;
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	unsigned int low = 0, high = 2E9 + 1, mid;
	while (low < high){
		mid = low + high >> 1;
		if (check(mid))
			low = mid + 1;
		else
			high = mid;
	}
	printf("%d\n", low - 1);
	return 0;
}