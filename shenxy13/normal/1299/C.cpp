#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<double, ii> pda;
int main() {
	int n;
	scanf("%d", &n);
	long long a[n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
	vector<pda> oof;
	for (int i = 1; i <= n; ++i) {
		pda x = pda(a[i] - a[i - 1], ii(i, i));
		while (!oof.empty() && oof.back().first >= x.first) x = pda((a[i] - a[oof.back().second.first - 1]) / (double) (i - oof.back().second.first + 1), ii(oof.back().second.first, i)), oof.pop_back();
		oof.push_back(x);
	}
	for (pda a: oof) {
		for (int i = a.second.first; i <= a.second.second; ++i) printf("%.9lf\n", a.first);
	}
	return 0;
}