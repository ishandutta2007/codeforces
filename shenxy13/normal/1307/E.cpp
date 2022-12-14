#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define int long long
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
const int INF = 10000;
const int mod = 1000000007;
int32_t main() {
	int n, m, s, h;
	scanf("%lld %lld", &n, &m);
	vector<int> grass[n + 1];
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &s);
		grass[s].push_back(i);
	}
	vector<ii> smth[n + 1];
	iii ranges[m];
	for (int i = 0; i < m; ++i) {
		scanf("%lld %lld", &s, &h);
		if (grass[s].size() < h) ranges[i] = iii(ii(INF, -INF), s);
		else ranges[i] = iii(ii(grass[s][h - 1], grass[s][grass[s].size() - h]), s);
		smth[s].push_back(ranges[i].first);
	}
	sort(ranges, ranges + m);
	int cow = 0;
	long long num = 1;
	int cw = 0;
	long long nm = 1;
	for (int j = 1; j <= n; ++j) {
		long long ct = 0;
		for (ii k: smth[j]) {
			if (k.second > 0) ++ct;
		}
		if (ct) ++cw, nm = nm * ct % mod;
	}
	if (cw > cow) cow = cw, num = nm;
	else if (cw == cow) num += nm;
	for (int i = 0; i < m; ++i) {
		if (ranges[i].first.first == INF) break;
		int cw = 1;
		long long nm = 1;
		for (int j = 1; j <= n; ++j) {
			if (j == ranges[i].second) {
				int ct = 0;
				for (ii k: smth[j]) {
					if (k == ranges[i].first) continue;
					if (k.second > ranges[i].first.first) ++ct;
				}
				if (ct != 0) ++cw, nm = nm * ct % mod;
			} else {
				long long ct1 = 0, ct2 = 0, ct3 = 0;
				for (ii k: smth[j]) {
					if (k.second > ranges[i].first.first && k.first < ranges[i].first.first) ++ct3;
					if (k.second > ranges[i].first.first) ++ct2;
					if (k.first < ranges[i].first.first) ++ct1;
				}
				if ((ct1 == 0 && ct2 == 0));
				else if (ct1 == 0 || ct2 == 0 || ct1 * ct2 == ct3) ++cw, nm = nm * (ct1 + ct2) % mod;
				else cw += 2, nm = nm * ((ct1 * ct2 - ct3) % mod) % mod;
			}
		}
		if (cw > cow) cow = cw, num = nm;
		else if (cw == cow) num = (num + nm) % mod;
	}
	if (cow == 0) num = 1;
	printf("%lld %lld", cow, ((num % mod) + mod) % mod);
	return 0;
}