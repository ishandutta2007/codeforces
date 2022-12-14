#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef map<int, int> mi;
typedef map<int, mi> mii;
typedef map<int, mii> miii;
int main() {
	int n;
	scanf("%d", &n);
	int x[n], y[n], z[n];
	miii sch;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
		sch[x[i]][y[i]][z[i]] = i;
	}
	bool taken[n];
	fill_n(taken, n, false);
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			sch[x[i]][y[i]].erase(z[i]);
			if (sch[x[i]][y[i]].empty()) sch[x[i]].erase(y[i]);
			if (sch[x[i]].empty()) sch.erase(x[i]);
			miii::iterator it1 = sch.lower_bound(x[i]);
			if (it1 == sch.end()) --it1;
			mii::iterator it2 = it1 -> second.lower_bound(y[i]);
			if (it2 == it1 -> second.end()) --it2;
			mi::iterator it3 = it2 -> second.lower_bound(z[i]);
			if (it3 == it2 -> second.end()) --it3;
			taken[it3 -> second] = true;
			printf("%d %d\n", i + 1, it3 -> second + 1);
			int j = it3 -> second;
			sch[x[j]][y[j]].erase(z[j]);
			if (sch[x[j]][y[j]].empty()) sch[x[j]].erase(y[j]);
			if (sch[x[j]].empty()) sch.erase(x[j]);
		}
	}
	return 0;
}