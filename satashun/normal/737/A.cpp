#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n, k, s, t;
int p[200010];
int c[200010];
int v[200010];

bool ok(ll x)
{
	ll u = 0;
	for (int i = 0; i <= k; ++i) {
		ll d = p[i+1] - p[i];
		if (x < d) {
			return false;
		}
		ll m = min(x - d, d);
		u += d*2-m;
	}

	return u <= (ll)t;
}

int main() {
	scanf("%d %d %d %d", &n, &k, &s, &t);

	rep(i, n) {
		scanf("%d %d", &c[i], &v[i]);
	}

	rep(i, k) scanf("%d", &p[i + 1]);
	sort(p, p + k + 1);
	p[k + 1] = s;

	ll lo = 0, hi = 2e9;

	while (hi - lo > 1) {
		ll m = (lo + hi) / 2;
		if (ok(m)) {
			hi = m;
		} else {
			lo = m;
		}
	}
	int ans = INT_MAX;

	rep(i, n) if ((ll)v[i] >= hi) {
		ans = min(ans, c[i]);
	}

	if (ans == INT_MAX) ans = -1;
	printf("%d\n", ans);

	return 0;
}