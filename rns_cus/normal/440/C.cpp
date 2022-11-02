#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 101

ll a[M] = {0};

int calc(ll n, int k) {
	if (!k) {
		return n;
	}
    int r = n / a[k];
    int x = r * k + calc(n - r * a[k], k - 1);
    int y = (r + 1) * k + calc(r * a[k] + a[k] - n, k - 1);
    return min(x, y);
}

int main() {
	for (int i = 1; i < M; i++) {
		a[i] = a[i-1] * 10 + 1;
	}
	///freopen("C.in", "r", stdin);
	ll n;
    scanf("%I64d", &n);
    printf("%d\n", calc(n, 17));
	return 0;
}