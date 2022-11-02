#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define eb emplace_back
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

ll N;

int main()
{
	scanf("%lld", &N);
	if (N == 0) printf("0 0\n");
	else {
		ll lo = 1, hi = 1e9;
		while (lo < hi) {
			ll mid = (lo+hi)/2;
			if (mid * (mid+1) * 3 >= N) hi = mid;
			else lo = mid + 1;
		}
		ll l = lo;
		N -= (l-1)*l*3;
		N %= (6*l);
		if (N < l) {
			printf("%lld %lld\n", 2*l - N, 2*N);
			return 0;
		}
		N -= l;
		if (N < l) {
			printf("%lld %lld\n", l - 2*N, 2*l);
			return 0;
		}
		N -= l;
		if (N < l) {
			printf("%lld %lld\n", -l - N, 2*l - 2*N);
			return 0;
		}
		N -= l;
		if (N < l) {
			printf("%lld %lld\n", -2*l + N, -2*N);
			return 0;
		}
		N -= l;
		if (N < l) {
			printf("%lld %lld\n", -l + 2*N, -2*l);
			return 0;
		}
		N -= l;
		if (N < l) {
			printf("%lld %lld\n", l + N, -2*l + 2*N);
			return 0;
		}
	}
}