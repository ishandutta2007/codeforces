#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1E3 + 10, MAXC = 8, MAXM = 1 << MAXC;
const int INF = 1 << 30;

int n;
int a[MAXN];

int cnt[MAXC], id[MAXN];
vector<int> loc[MAXC];

int check(int limit){
	static int dp[MAXN][MAXM];
	static bool initFlag = false;
	if (!initFlag){
		fill_n(dp[0], MAXM, -INF);
		dp[0][0] = 0;
		initFlag = true;
	}

	if (limit == 0){
		int ret = 0;
		for (int i = 0; i < MAXC; ++i)
			ret += !!cnt[i];
		return ret;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < MAXM; ++j){
			dp[i][j] = dp[i - 1][j];
			if (~j >> a[i] & 1)
				continue;
			if (id[i] >= limit - 1)
				dp[i][j] = max(dp[i][j], dp[loc[a[i]][id[i] - (limit - 1)] - 1][j ^ 1 << a[i]]);
			if (id[i] >= limit)
				dp[i][j] = max(dp[i][j], dp[loc[a[i]][id[i] - limit] - 1][j ^ 1 << a[i]] + 1);
		}
	return dp[n][MAXM - 1];
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		id[i] = cnt[--a[i]]++;
		loc[a[i]].push_back(i);
	}
	int low = 1, high = n / MAXC + 1, mid;
	while (low < high){
		mid = low + (high - low >> 1);
		if (check(mid) >= 0)
			low = mid + 1;
		else
			high = mid;
	}
	--low;
	printf("%d\n", low * MAXC + check(low));
	return 0;
}