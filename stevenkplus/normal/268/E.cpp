#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<double, int> pdi;

const double eps = 1E-10;
const int MAXN = 100100;

pdi sortby[MAXN];

int L[MAXN];
double P[MAXN];

int N;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int l, p;
		scanf("%d %d", &l, &p);
		L[i] = l;
		P[i] = p / 100.;
		sortby[i] = pdi((1 - P[i]) / (eps + P[i] * L[i]), i);
	}

	sort(sortby, sortby + N);

	double len = 0;
	double sum = 0;
	for(int i = 0; i < N; ++i) {
		int cur = sortby[i].second;
		sum += L[cur];
		sum += len * (1 - P[cur]);
		len += L[cur] * P[cur];
	}

	printf("%.20f\n", sum);
	return 0;
}