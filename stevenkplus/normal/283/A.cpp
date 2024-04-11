#include <cstdio>

using namespace std;

const int MAXN = 200100;

int add[MAXN];
int ar[MAXN];

int N;
int main() {
	scanf("%d", &N);
	double cursum = 0;
	int curcnt = 1;

	for(int i = 0; i < N; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, a;
			scanf("%d %d", &a, &x);
			add[a] += x;

			cursum += x * a;
		} else if (t == 2) {
			int k;
			scanf("%d", &k);
			cursum += k;
			ar[curcnt] = k;
			++curcnt;
		} else {
			cursum -= add[curcnt];
			add[curcnt - 1] += add[curcnt];
			add[curcnt] = 0;

			--curcnt;
			cursum -= ar[curcnt];
		}

		double av = cursum / curcnt;
		printf("%.10f\n", av);
	}

	return 0;
}