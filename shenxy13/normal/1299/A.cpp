#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int n;
	scanf("%d", &n);
	ii a[n];
	for (int i = 0; i < n; ++i) scanf("%d", &a[i].second);
	int idx = -1, k = 0;
	int stp[30];
	fill_n(stp, 30, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 30; ++j) {
			if ((1 << j) & a[i].second) ++stp[j];
		}
	}
	for (int i = 0; i < n; ++i) {
		a[i].first = 0;
		for (int j = 0; j < 30; ++j) {
			if ((1 << j) & a[i].second && stp[j] == 1) a[i].first += (1 << j);
		}
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; --i) printf("%d ", a[i].second);
	return 0;
}