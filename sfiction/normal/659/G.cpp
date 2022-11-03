#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1E9 + 7;

int main(){
	int n;
	int pre, now, val = 0;
	ll ans;
	scanf("%d", &n);
	scanf("%d", &pre);
	ans = --pre;
	ll sum = 0;
	for (int i = 1; i < n; ++i){
		scanf("%d", &now);
		ans += --now;
		sum *= min(val, now);
		ans += (sum %= MOD) * (val = min(pre, now)) % MOD;
		sum += val;
		ans += val * (ll)val % MOD;
		pre = now;
	}
	printf("%d\n", (int)(ans % MOD));
	return 0;
}