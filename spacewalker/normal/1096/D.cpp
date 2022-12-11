#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;


/*
compute dp[i][k]: what is the minimum cost of altering the 
ith prefix of S so that the kth prefix of hard does not appear?, (but the k-1st does)
dp[0][i] = 0; the null string does not have hard
dp[i][0] is just the total cost of all Hs

so for further cases:
dp[i][k]
if S[i] is not hard[k]; this character is irrelevant. ignore.
if it is, we have some choices:
- do not complete the k-1st prefix. so take dp[i-1][k-1]
- complete the k-1th prefix, but delete current character. so dp[i-1][k] + a[i]
- answer is dp[n][3]
*/

ll optDelete[100010][7];
const char toDel[] = "hard";
char str[100010];

int main() {
	int n; scanf("%d", &n);
	scanf("%s", str);
	vector<int> costs(n);
	for (int i = 0; i < n; ++i) scanf("%d", &costs[i]);
	for (int i = 1; i <= n; ++i) {
		// printf("%d OPT ", i);
		for (int k = 0; k < 4; ++k) {
			if (str[i-1] != toDel[k]) optDelete[i][k] = optDelete[i-1][k];
			else if (k == 0) {
				optDelete[i][k] = optDelete[i-1][k] + costs[i-1];
			} else {
				optDelete[i][k] = min(optDelete[i-1][k-1],
					optDelete[i-1][k] + costs[i-1]);
			}
			// printf("%lld ", optDelete[i][k]);
		}
		// printf("\n");
	}
	printf("%lld\n", optDelete[n][3]);
	return 0;
}