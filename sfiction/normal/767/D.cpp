#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1E6 + 10;

int n, m, K;
ll a[MAXN], b[MAXN];
ll c[MAXN << 1];

bool check(int n, ll a[]){
	static const ll STEP = 1ll << 32;
	int i = 0;
	for (ll j = 0; i < n && c[i] >= j; i += K, j += STEP);
	return i >= n;
}

int main(){
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i), a[i] <<= 32;
	for (int i = 0; i < m; ++i)
		scanf("%lld", b + i), b[i] = b[i] << 32 | i + 1;
	sort(a, a + n), sort(b, b + m);
	int low = 0, high = m + 1, mid;
	while (low < high){
		mid = low + (high - low >> 1);
		merge(a ,a + n, b + m - mid, b + m, c);
		if (check(n + mid, c))
			low = mid + 1;
		else
			high = mid;
	}
	printf("%d\n", low - 1);
	if (low > 1){
		for (int i = m - low + 1; i < m; ++i)
			printf("%lld%c", b[i] & INT_MAX, "\n "[i + 1 < m]);
	}
	return 0;
}