#include <cstdio>

typedef long long ll;

int main(){
	ll n;
	scanf("%I64d", &n);
	ll high = 1E8, low = 0, mid;
	while (low < high){
		mid = high + low >> 1;
		if (mid * (mid + 1) / 2 < n)
			low = mid + 1;
		else
			high = mid;
	}
	printf("%I64d\n", n - low * (low - 1) / 2);
	return 0;
}