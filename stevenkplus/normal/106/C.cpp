#include <cstdio>

using namespace std;

const int MAXN = 1010;
const int MAXM = 20;

int N, M;

int A[MAXN];
int B[MAXN];
int C[MAXN];
int D[MAXN];

int dp[MAXN][MAXM];

int get(int dough, int ind) {
	if (ind > M) return 0; // base case

	//memoization
	int &ret = dp[dough][ind];
	if (ret) return ret - 1;
	//find answer

	for(int i = 0; i * B[ind] <= A[ind] && i * C[ind] <= dough; ++i) {
		int money = i * D[ind] + get(dough - i * C[ind], ind + 1);
		if (money > ret) ret = money;
	}

	++ret;
	return ret - 1;
	// return ret++;
}

int main() {
	scanf("%d %d %d %d", &N, &M, C, D);
	for(int i = 1; i <= M; ++i) {
		scanf("%d %d %d %d", A + i, B + i, C + i, D + i);
	}

	int ans = get(N, 0);

	printf("%d\n", ans);
	return 0;
}