#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int N = 50;

char ans[N][N];

int main() {
	int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
	// printf("HERE\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i < 25) {
				if (j < 25) ans[i][j] = 'A';
				else ans[i][j] = 'B';
			} else {
				if (j < 25) ans[i][j] = 'C';
				else ans[i][j] = 'D';
			}
		}
	}
	// printf("HERE\n");
	--a; --b; --c; --d;
	for (int atp = 0; atp < a; ++atp) {
		ans[2*(atp/12)][(24-2*(atp%12))+25] = 'A';
	}
	for (int btp = 0; btp < b; ++btp) {
		ans[2*(btp/12)][2*(btp%12)] = 'B';
	}
	for (int ctp = 0; ctp < c; ++ctp) {
		ans[2*(ctp/12) + 25][(24-2 * (ctp%12)) + 25] = 'C';
	}
	for (int dtp = 0; dtp < d; ++dtp) {
		ans[2*(dtp/12)+25][2*(dtp%12)] = 'D';
	}
	printf("%d %d\n", N, N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
}