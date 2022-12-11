#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#define int long long

using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;

// E[i] = (sum_of_E[j] + sum_of_dists[j])/(j+1)

// SOD[j] = (j+1)*(x[i]**2 + y[i]**2) - 2(sox[i])x[i] - 2(soy[i])y[i] + sosx[i] + sosy[i]
// sox, sosx, soy, sosy[j]

ll FMOD(ll x) {
	return (x % MOD + MOD) % MOD;
}

ll modexp(ll b, ll e) {
	if (e == 0) return 1;
	else return (e % 2 == 1 ? b : 1) * modexp((b*b)%MOD, e/2) % MOD;
}

ll modinv(ll x) {
	return modexp(x, MOD - 2);
}

int grid[1010][1010];

int32_t main() {
	int n, m; scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%lld", &grid[i][j]);
		}
	}
	vector<pair<int, int>> cellToWork(n*m);
	vector<int> valList(n*m);
	for (int i = 0; i < n*m; i += m) {
		for (int j = 0; j < m; ++j) {
			cellToWork[i + j] = make_pair(i/m, j);
			valList[i+j] = grid[i/m][j];
		}
	}
	sort(cellToWork.begin(), cellToWork.end(), [] (pair<int, int> i, pair<int, int> j) {
		return grid[i.first][i.second] < grid[j.first][j.second];
	});
	sort(valList.begin(), valList.end());
	vector<ll> expect(n*m), sumx(n*m), sumsqx(n*m), sumy(n*m), sumsqy(n*m), sumex(n*m);
	for (int i = 0; i < n*m; ++i) {
		ll cx = cellToWork[i].first, cy = cellToWork[i].second;
		if (valList[i] > valList[0]) {
			int j = distance(valList.begin(), lower_bound(valList.begin(), valList.end(), valList[i])) - 1;
			ll sumOfDist = FMOD(((j+1) * (cx*cx % MOD + cy*cy % MOD) % MOD + sumsqx[j] + sumsqy[j]) % MOD
				- (2 * sumx[j] % MOD * cx % MOD + 2 * sumy[j] % MOD * cy % MOD));
			expect[i] = ((sumex[j] + sumOfDist) % MOD * modinv(j + 1)) % MOD;
		}
		// else 
		if (i == 0) {
			sumx[i] = cx;
			sumsqx[i] = cx*cx % MOD;
			sumy[i] = cy;
			sumsqy[i] = cy*cy % MOD;
		} else {
			sumx[i] = (sumx[i-1] + cx) % MOD;
			sumy[i] = (sumy[i-1] + cy) % MOD;
			sumsqx[i] = (sumsqx[i-1] + cx*cx%MOD) % MOD;
			sumsqy[i] = (sumsqy[i-1] + cy*cy%MOD) % MOD;
			sumex[i] = (sumex[i-1] + expect[i]) % MOD;
		}
	}
	int r, c; scanf("%lld %lld", &r, &c); --r; --c;
	for (int i = 0; i < n*m; ++i) {
		if (cellToWork[i].first == r && cellToWork[i].second == c) {
			printf("%lld\n", expect[i]);
			return 0;
		}
	}
	return 0;
}