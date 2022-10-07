#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1010;
pii ar[MAXN];
int N;
int main() {
	scanf("%d", &N);

	for(int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ar[i] = pii(a, b);
	}
	sort(ar, ar + N);

	int maxq = 0;

	int curq = 0;
	int prv = 0;
	for(int i = 0; i < N; ++i) {
		int t = ar[i].first;
		int n = ar[i].second;
		curq -= (t - prv);
		prv = t;
		if (curq < 0) curq = 0;

		curq += n;
		if (curq > maxq) maxq = curq;
	}

	int lastt = ar[N - 1].first;
	int ans = lastt + curq;
	printf("%d %d\n", ans, maxq);
	return 0;
}