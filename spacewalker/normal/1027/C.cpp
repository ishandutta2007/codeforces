#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;
typedef long long ll;

pair<ll, ll> better(pair<ll, ll> x, pair<ll, ll> y) {
	ll a = x.first, b = x.second, c = y.first, d = y.second;
	return ((a*a + b*b) * c*d < (c*c + d*d) * a*b ? x : y);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		unordered_map<int, int> tbl;
		vector<ll> finalLength;
		for (int i = 0; i < n; ++i) tbl[arr[i]]++;
		int sureSide = -1;
		for (auto a_ct : tbl) {
			if (a_ct.second <= 1) continue;
			else if (a_ct.second >= 4) sureSide = a_ct.first;
			else finalLength.push_back(a_ct.first);
		}
		if (sureSide >= 0) {
			printf("%d %d %d %d\n", sureSide, sureSide, sureSide, sureSide);
			continue;
		}
		sort(finalLength.begin(), finalLength.end());
		pair<ll, ll> bestAns = better(make_pair(finalLength[0], finalLength[1]),
			make_pair(finalLength[finalLength.size()-1], finalLength[finalLength.size()-2]));
		for (int i = 1; i < finalLength.size() - 1; ++i) {
			bestAns = better(bestAns, better(make_pair(finalLength[i], finalLength[i-1]),
				make_pair(finalLength[i], finalLength[i+1])));
		}
		printf("%lld %lld %lld %lld\n", bestAns.first, bestAns.second, bestAns.first, bestAns.second);
	}
	return 0;
}