#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
typedef pair<int, int> pii;

const int MAXN = 100100;

vector<pii> ones, twos;
int N, M;
int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		vector<pii> &v = a == 1 ? ones : twos;
		v.push_back(pii(b, i));
	}
	sort(ones.rbegin(), ones.rend());
	sort(twos.rbegin(), twos.rend());
	int mcap = 0, ans1 = 0, ans2 = 0;
	int numones = ones.size(), numtwos = twos.size();
	int curcap = 0, curvol = 0;
	int i;
	for(i = 0; i <= numones && curvol <= M; ++i) {
		if (curcap > mcap) {
			mcap = curcap;
			ans1 = i;
		}
		if (i < numones) {
			curvol ++;
			curcap += ones[i].first;
		} else {
			break;
		}
	}
	--i;
//	printf("i = %d, curvol = %d, curcap = %d, mcap = %d\n", i, curvol, curcap, mcap);
	for(int j = 0; j < numtwos; ++j) {
		curvol += 2;
		curcap += twos[j].first;
		while (i >= 0 && curvol > M) {
			curvol--;
			curcap -= ones[i].first;
			--i;
		}
//	printf("i = %d, curvol = %d, curcap = %d, mcap = %d\n", i, curvol, curcap, mcap);
		if (curvol > M) {
			break;
		}
		if (curcap > mcap) {
			mcap = curcap;
			ans1 = i + 1;
			ans2 = j + 1;
		}
	}
	printf("%d\n", mcap);
	bool first = true;
	for(int i = 0; i < ans1; ++i) {
		if (!first) printf(" ");
		first = false;
		printf("%d", ones[i].second + 1);
	}
	for(int i = 0; i < ans2; ++i) {
		if (!first) printf(" ");
		first = false;
		printf("%d", twos[i].second + 1);
	}
	printf("\n");
	return 0;
}