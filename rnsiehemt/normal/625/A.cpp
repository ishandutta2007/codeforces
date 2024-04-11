#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

ll n, a, b, c, ans;

int main()
{
	scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
	if (a <= b-c) {
		ans = n / a;
	} else {
		ll extra = n - b;
		if (extra >= 0) {
			ll times = extra / (b-c) + 1;
			ans += times;
			n -= times * (b-c);
		}
		ans += n/a;
	}
	printf("%lld\n", ans);
}