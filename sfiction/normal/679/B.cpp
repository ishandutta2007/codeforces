#include <cstdio>
#include <cmath>
#include <algorithm>

typedef long long ll;

const int MAXN = 1E5 + 10;

int h[MAXN];
ll tot[MAXN];

inline ll sqr3(ll x){
	return x * x * x;
}

int sqrt3(ll x){
	ll r = pow(x, 1.0 / 3) - 2;
	for (; sqr3(r) <= x; ++r);
	return r - 1;
}

int main(){
	ll m;
	scanf("%I64d", &m);
	int n = sqrt3(m);
	for (int i = 2; i <= n + 1; ++i){
		h[i] = h[i - 1], tot[i] = tot[i - 1];
		ll s = sqr3(i - 1), s0 = std::min(m, sqr3(i) - 1);
		int t = 1;
		for (; s <= s0; ){
			int n1 = sqrt3(s0 - s);
			if (h[i] < t + h[n1] || h[i] == t + h[n1] && tot[i] < s + tot[n1]){
				h[i] = t + h[n1];
				tot[i] = s + tot[n1];
			}
			if (!n1)
				break;
			++t;
			s += sqr3(n1);
		}
	}
	printf("%d %I64d\n", h[n + 1], tot[n + 1]);
	return 0;
}