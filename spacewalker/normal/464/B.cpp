#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll>> pts(8);
vector<ll> MAGIC{0, 1, 1, 1, 2, 2, 2, 3};

ll sqdist(int i, int j) {
	ll ans = 0;
	for (int k = 0; k < 3; ++k) ans += (pts[i][k] - pts[j][k]) * (pts[i][k] - pts[j][k]);
	return ans;
}

bool checkCube() {
	// check if current arrangement forms a cube
	ll baseDist = -1;
	for (int i = 0; i < 8; ++i) {
		vector<int> ptidx(8);
		for (int j = 0; j < 8; ++j) ptidx[j] = j;
		sort(ptidx.begin(), ptidx.end(), [i] (int x, int y) {
			return sqdist(i, x) < sqdist(i, y);
		});
		if (baseDist == -1) {
			baseDist = sqdist(ptidx[1], i);
		} else if (baseDist == 0) {
			return false;
		}
		for (int j = 0; j < 8; ++j) {
			if (sqdist(ptidx[j], i) != MAGIC[j] * baseDist) return false;
		}
	}
	return true;
}

void find_cube(int i) {
	if (i == 8) {
		// printf("checking arr:\n");
		// for (auto &pt : pts) {
		// 		for (ll k : pt) printf("%lld ", k);
		// 		printf("\n");
		// }
		if (checkCube()) {
			printf("YES\n");
			for (auto &pt : pts) {
				for (ll k : pt) printf("%lld ", k);
				printf("\n");
			}
			exit(0);
		}
	} else {
		do {
			find_cube(i+1);
		} while (next_permutation(pts[i].begin(), pts[i].end()));
	}
}

int main() {
	for (int i = 0; i < 8; ++i) {
		ll x, y, z; scanf("%lld %lld %lld", &x, &y, &z);
		pts[i] = vector<ll>{x, y, z};
		sort(pts[i].begin(), pts[i].end());
	}
	find_cube(0);
	printf("NO\n");
	return 0;
}