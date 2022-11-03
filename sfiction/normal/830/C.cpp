#include <climits>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1E2 + 10;

int n;
ll K;
ll a[MAXN];
vector<ll> b;

int main(){
	scanf("%d%lld", &n, &K);
	for (int i = 0; i < n; ++i){
		scanf("%lld", a + i);
		K += a[i];
		for (int j = 1; ; ++j){
			int t = (a[i] + j - 1) / j;
			if (j < t)
				b.push_back(t), b.push_back(j);
			else if (t == j)
				b.push_back(j);
			else
				break;
		}
	}
	b.push_back(LLONG_MAX);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	ll ans = 1;
	for (int i = 1; i < b.size(); ++i){
		int d = b[i - 1];
		ll ds = 0;
		for (int j = 0; j < n; ++j)
			ds += (a[j] + d - 1) / d;
		ds = min(K / ds, b[i] - 1);
		if (d <= ds)
			ans = max(ans, ds);
	}
	printf("%lld\n", ans);
	return 0;
}