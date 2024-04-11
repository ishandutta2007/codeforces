#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1 << 17;
const int inf = (1 << 30 - 1) + (1 << 30);
const double eps = 1E-8;

int N;
pii ar[MAXN];
int minpref[MAXN], maxpref[MAXN];
int minsuff[MAXN], maxsuff[MAXN];

void prec() {
	minpref[0] = inf;
	maxpref[0] = -inf;
	for(int i = 0; i < N; ++i) {
		int v = ar[i].second;
		minpref[i + 1] = min(minpref[i], v);
		maxpref[i + 1] = max(maxpref[i], v);
	}
	minsuff[N] = inf;
	maxsuff[N] = -inf;
	for(int i = N - 1; i >= 0; --i) {
		int v = ar[i].second;
		minsuff[i] = min(minsuff[i + 1], v);
		maxsuff[i] = max(maxsuff[i + 1], v);
	}
}


pii conv(int x, int y) {
	return pii(x + y, x - y);
}

bool works(double d) {
	int left = 0, right = 0;
	while (right < N) {
		if (ar[left].first + 2 * d >= ar[right].first) {
			int minval = min(minpref[left], minsuff[right + 1]);
			int maxval = max(maxpref[left], maxsuff[right + 1]);
			if (minval + 2 * d >= maxval) {
				return true;
			}
			++right;
		} else {
			++left;
		}
	}
	return false;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ar[i] = conv(a, b);
	}

	sort(ar, ar + N);
	prec();

	double low = 0;
	double step = 1E9;

	while (step > eps) {
		double mid = low + step;
		if (!works(mid)) {
			low += step;
		}
		step /= 2;
	}

	printf("%.10f\n", low);
	return 0;
}