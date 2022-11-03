#include <cstdio>

typedef long long ll;

int main(){
	ll n;
	scanf("%I64d", &n);
	++n;
	int high = 6E8, low = 0, mid;
	while (high > low){
		mid = high + low >> 1;
		ll t = 1 + 3 * mid * (ll)(mid + 1);
		if (n <= t)
			high = mid;
		else
			low = mid + 1;
	}
	int m = low;
	n -= 1 + 3 * m * (ll)(m - 1);
	if (n <= m){
		int t = n;
		printf("%d %d\n", (m << 1) - t, t << 1);
	}
	else if (n <= 2ll * m){
		int t = n - m;
		printf("%d %d\n", m - (t << 1), m << 1);
	}
	else if (n <= 3ll * m){
		int t = n - 2 * m;
		printf("%d %d\n", -m - t, m - t << 1);
	}
	else if (n <= 4ll * m){
		int t = n - 3 * m;
		printf("%d %d\n", -(m << 1) + t, -(t << 1));
	}
	else if (n <= 5ll * m){
		int t = n - 4 * m;
		printf("%d %d\n", (t << 1) - m, -(m << 1));
	}
	else{
		int t = n - 5 * m;
		printf("%d %d\n", m + t, -(m - t << 1));
	}
	return 0;
}