#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
bitset<1000> want, have;
int main() {
	int n, ans = 0, opt = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		if (n - (n + i - 1) / i - i + 1 > ans) {
			ans = n - (n + i - 1) / i - i + 1;
			opt = i;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i % opt) want[i] = 1, have[i] = 0;
		else want[i] = 0, have[i] = 0;
	}
	vector<int> moves;
	for (int i = 0; i < 10000; ++i) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (have[i]) ++cnt;
		}
		if (cnt == ans) {
			printf("0");
			fflush(stdout);
			return 0;
		}
		moves.clear();
		for (int i = 0; i < n; ++i) {
			if (want[i] && !have[i]) moves.push_back(i + 1);
		}
		for (int i = 0; i < opt; ++i) have[moves[i] - 1] = 1;
		printf("%d\n", opt);
		printf("%d", moves[0]);
		for (int i = 1; i < opt; ++i) printf(" %d", moves[i]);
		printf("\n");
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (x == -1) return 1;
		--x;
		for (int i = 0; i < opt; ++i) have[(x + i) % n] = 0;
	}
	return 2;
}