#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<double, int> plant;
#define loc second

const int MAXN = 5100;
plant ar[MAXN];

int dp[MAXN][MAXN];
int N, M;

int getdp(int cur, int prv) {
	if (cur == N) {
		return 0;
	}
	int &ret = dp[cur][prv];
	if (ret) return ret - 1;

	int num = ar[cur].loc;
	if (num < prv) {
		ret = 1 + getdp(cur + 1, prv);
	} else if (num == prv) {
		ret = getdp(cur + 1, prv);
	} else {
		ret = min(getdp(cur + 1, num), 1 + getdp(cur + 1, prv));
	}

	return ret++;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i) {
		int a; double b;
		scanf("%d %lf", &a, &b);
		ar[i] = plant(b, a);
	}

//	sort(ar, ar + N);

	int ans = getdp(0, 0);
	printf("%d\n", ans);
	return 0;
}