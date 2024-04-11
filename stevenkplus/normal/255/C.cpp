#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 4100;

int ar[MAXN];
int dp[MAXN][MAXN];

map<int, int> mymap;

int N;

int main() {
	scanf("%d", &N);
	int cnt = 1;
	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		int &m = mymap[tmp];
		if (m == 0) m = cnt++;
		ar[i] = m;
	}

	int ans = 0;
	for(int i = 0; i < N; ++i) {
		int cur = ar[i];
		for(int j = 1; j < cnt; ++j) {
			dp[j][cur] = max(dp[cur][j], 1 + dp[cur][j]);
			ans = max(ans, dp[j][cur]);
		}
	}
	printf("%d\n", ans);
	return 0;
}