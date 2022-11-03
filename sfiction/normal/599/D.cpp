#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;

int main(){
	vector<PLL> a;
	ll x;
	scanf("%I64d", &x);
	x *= 6;
	for (ll t = 2, i = 1; ; ++i, t += i << 1){
		ll res = x % t;
		if (x / t < (i << 1))
			break;
		if (x % t)
			continue;
		ll m = x / t + i - 1;
		if (m % 3)
			continue;
		if ((m /= 3) >= i)
			a.push_back(PLL(i, m));
		else
			break;
	}
	if (a.size()){
		int ans = (a.size() << 1) - (a.back().first == a.back().second);
		printf("%d\n", ans);
		for (int i = 0; i < a.size(); ++i)
			printf("%I64d %I64d\n", a[i].first, a[i].second);
		for (int i = (int)a.size() - 1 - (ans & 1); i >= 0; --i)
			printf("%I64d %I64d\n", a[i].second, a[i].first);
	}
	else
		puts("0");
	return 0;
}