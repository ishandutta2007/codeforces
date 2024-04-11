#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

ll N;

ll f(ll a) {
	return (a*(a+1))/2;
}

int main()
{
	scanf("%lld", &N);
	ll lo = 1, hi = 1e8;
	while (lo < hi) {
		ll mid = (lo+hi)/2;
		if (f(mid) < N) lo = mid+1;
		else hi = mid;
	}
	printf("%lld\n", lo - (f(lo) - N));
}