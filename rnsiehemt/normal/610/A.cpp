#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int main()
{
	ll N;
	scanf("%lld", &N);
	if (N&1) printf("0\n");
	else {
		ll K = N/4;
		if (K*4 == N) K--;
		if (K < 1) printf("0\n");
		else printf("%lld\n", K);
	}
}