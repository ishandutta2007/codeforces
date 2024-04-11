#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100100;
ll dist[MAXN];
vector<pii> conn[MAXN];

void vis(int cur, int par, ll dst) {
	dist[cur] = dst;
	repi(i, conn[cur]) {
		if (i->first != par) {
			vis(i->first, cur, dst + i->second);
		}
	}
}

int N;

int main() {
	scanf("%d", &N);
	ll sum = 0;
	for(int i = 1; i < N; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		sum += 2 * c;
		conn[a].push_back(pii(b, c));
		conn[b].push_back(pii(a, c));
	}
	vis(1, -1, 0);
	ll maxd = 0;
	for(int i = 1; i <= N; ++i) {
		if (dist[i] > maxd) {
			maxd = dist[i];
		}
	}

	ll ans = sum - maxd;
	printf("%I64d\n", ans);
	return 0;
}