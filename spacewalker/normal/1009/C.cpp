#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ll bestSum = 0;
	ll n, m; scanf("%lld %lld", &n, &m);
	ll h1c = n/2 + 1, h2c = n - h1c + 1;
	for (int i = 0; i < m; ++i) {
		ll x, d; scanf("%lld %lld", &x, &d);
		bestSum += n*x + (d > 0 ? n*(n-1)/2 : h1c*(h1c-1)/2 + h2c*(h2c-1)/2)*d;
	}
	printf("%.10lf\n", double(bestSum/(double)n));
}