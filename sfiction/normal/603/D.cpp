#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;

const int MAXN = 2E3 + 10;

ll a[MAXN], b[MAXN], c[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; ++i){
		scanf("%I64d%I64d%I64d", &a[i], &b[i], &c[i]);
		cnt += c[i] == 0;
	}
	int ans = cnt * (cnt - 1) / 2 * (n - cnt);
	for (int i = 0; i < n; ++i){
		if (!c[i])
			continue;
		map<PLL, int> lst;
		for (int j = i + 1; j < n; ++j){
			if (!c[j])
				continue;
			ll p = -c[j] * (a[i] * b[j] - b[i] * a[j]);
			ll q = c[i] * (a[j] * a[j] + b[j] * b[j])
					- c[j] * (a[i] * a[j] + b[i] * b[j]);
			ll d = __gcd(p, q);
			p /= d;
			q /= d;
			if (q < 0)
				p = -p, q = -q;
			else if (q == 0)
				p = !!p;
			ans += lst[PLL(p, q)]++;
		}
	}
	printf("%d\n", ans);
	return 0;
}