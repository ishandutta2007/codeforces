#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
constexpr int NMAX = 3000100;

char curs[NMAX];
vector<int> pSideI[NMAX], nSideI[NMAX], zeroI;
vector<int> psmd[NMAX], nsmd[NMAX], zmd;

int main() {
	int n; scanf("%d", &n);
	vector<int> minDip(n), endVal(n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", curs);
		for (int j = 0; curs[j]; ++j) {
			endVal[i] += (curs[j] == '(' ? 1 : -1);
			minDip[i] = min(minDip[i], endVal[i]);
		}
		// printf("ev md %d = %d %d\n", i, endVal[i], minDip[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (endVal[i] == 0) {
			zeroI.push_back(i);
			zmd.push_back(minDip[i]);
		} else if (endVal[i] < 0) {
			nSideI[-endVal[i]].push_back(i);
			nsmd[-endVal[i]].push_back(minDip[i]);
		} else {
			pSideI[endVal[i]].push_back(i);
			psmd[endVal[i]].push_back(minDip[i]);
		}
	}
	sort(zmd.begin(), zmd.end());
	for (int i = 0; i < NMAX; ++i) {
		sort(psmd[i].begin(), psmd[i].end());
		sort(nsmd[i].begin(), nsmd[i].end());
	}
	ll ans = 0;
	for (int i : zeroI) {
		if (minDip[i] >= 0) {
			ans += distance(lower_bound(zmd.begin(), zmd.end(), endVal[i]), zmd.end());
		}
	}
	// printf("ans with zero %lld\n", ans);
	for (int bev = 0; bev < NMAX; ++bev) {
		// for (int md : nsmd[bev]) {
		// 	printf("ns of %d = %d\n", bev, md);
		// }
		for (int i : pSideI[bev]) {
			// printf("taking ps %d\n", i);
			if (minDip[i] >= 0) {
				ans += distance(lower_bound(nsmd[bev].begin(), nsmd[bev].end(), -endVal[i]), nsmd[bev].end());
			}
		}
		for (int i : nSideI[bev]) {
			if (minDip[i] >= 0) {
				ans += distance(lower_bound(psmd[bev].begin(), psmd[bev].end(), -endVal[i]), psmd[bev].end());
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}