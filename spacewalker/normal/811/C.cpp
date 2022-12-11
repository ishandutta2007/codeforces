#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <bitset>
#include <algorithm>
#define INF 1000000
using namespace std;

typedef long long ll;


int main() {
	int n; scanf("%d", &n);
	vector<int> cities(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &cities[i]);
	}

	map<int, int> leftcitye;
	map<int, int> rightcitye;
	for (int i = 0; i < n; ++i) {
		if (leftcitye.find(cities[i]) == leftcitye.end()) {
			leftcitye[cities[i]] = i;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (rightcitye.find(cities[i]) == rightcitye.end()) {
			rightcitye[cities[i]] = i;
		}
	}

	map<int, pair<int, int>> cityinterval;
	for (auto cityleft : leftcitye) {
		cityinterval[cityleft.first] = make_pair(cityleft.second, rightcitye[cityleft.first]);
	}


	vector<vector<char>> isGoodInterval(n, vector<char>());
	for (int start = 0; start < n; ++start) {
		isGoodInterval[start].resize(n - start, false);
		int maxLooseEnd = 0;
		for (int end = start; end < n; ++end) {
			if (cityinterval[cities[end]].first < start) {
				break;
			} else {
				maxLooseEnd = max(maxLooseEnd, cityinterval[cities[end]].second);
				// if we have tied up all loose ends
				if (maxLooseEnd <= end) {
					isGoodInterval[start][end - start] = true; 
				}
			}
		}
	}

	bitset<5001> included;

	vector<vector<int>> xorScore(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		xorScore[i].resize(n - i, 0);
		int cxor = 0;
		for (int j = i; j < n; ++j) {
			if (!included[cities[j]]) {
				included[cities[j]] = true;
				cxor = (cxor ^ cities[j]);
			}
			xorScore[i][j - i] = cxor;
		}
		included.reset();
	}


	vector<int> dp(n, 0);
	for (int right = 0; right < n; ++right) {
		if (right > 0) {
			dp[right] = dp[right - 1];
		}
		for (int left = 0; left <= right; ++left) {
			if (isGoodInterval[left][right - left]) {
				//printf("[%d, %d] is a candidate trailing interval\n", left, right);
				dp[right] = max(dp[right], xorScore[left][right - left] + (left == 0 ? 0 : dp[left - 1]));
			}
		}
	}

	//printf("ANSWER: ");
	printf("%d\n", dp[n-1]);

	return 0;
}