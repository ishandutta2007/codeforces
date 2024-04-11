#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 110;

pii cows[MAXN]; // pair(cost, cnt)

ll P[MAXN];

int N, T;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		cows[i] = pii(b, a);
	}
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
		scanf("%I64d", P + i);
	}

	sort(cows, cows + N);

	ll sum = 0;

	int f = 1;
	ll need = P[f];
	bool done = false;
	for(int i = 0; i < N; ++i) {
		ll c = cows[i].first;
		ll cnt = cows[i].second;
		while (!done && cnt >= need) {
			sum += need * f * c;
			cnt -= need;
			++f;
			if (f <= T) {
				need = P[f] - P[f - 1];
			} else {
				done = true;
			}
		}
		sum += cnt * f * c;
		need -= cnt;
	}

	printf("%I64d\n", sum);
	return 0;
}