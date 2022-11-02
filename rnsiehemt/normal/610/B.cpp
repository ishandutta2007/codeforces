#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N;
ll a[200005];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lld", a+i);
	ll k = *std::min_element(a, a+N);
	int lastmin = 0; ll ans = 0;
	for (int i = N+N; i--; ) {
		int j = i%N;
		if (a[j] == k) lastmin = i;
		domax(ans, k*N + (lastmin - i));
	}
	printf("%lld\n", ans);
}