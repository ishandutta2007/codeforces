#include <cstdio>

typedef long long ll;

const int MAXN = 3E5 + 10;

ll a[MAXN];

ll calc(ll x){
	ll ret = 0;
	for (int i = 2; a[i] <= x; ++i)
		ret += x / a[i];
	return ret;
}

int main(){
	for (int i = 2; i < MAXN; ++i)
		a[i] = 1ll * i * i * i;

	ll m;
	scanf("%I64d", &m);
	ll low = 0, high = 1E16, mid;
	while (low < high){
		mid = low + high >> 1;
		if (calc(mid) < m)
			low = mid + 1;
		else
			high = mid;
	}
	printf("%I64d\n", calc(low) == m ? low : -1);
	return 0;
}