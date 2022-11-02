#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

std::vector<ll> v;
ll a, b;

int main()
{
	for (int i = 2; i < 61; i++) {
		ll j = (1ll << i) - 1;
		for (int k = 0; k < i-1; k++) {
			ll p = j - (1ll << k);
			v.push_back(p);
		}
	}
	std::sort(v.begin(), v.end());
	scanf("%lld%lld", &a, &b);
	printf("%d\n", int(std::upper_bound(v.begin(), v.end(), b) - std::lower_bound(v.begin(), v.end(), a)));
}