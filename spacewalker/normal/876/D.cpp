#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> q(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &q[i]);
	}

	reverse(q.begin(), q.end());
	int rightmostCoin = 0;

	vector<int> answers(n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		rightmostCoin = max(rightmostCoin, q[i-1]);
		answers[i] = (rightmostCoin - i + 1);
	}
	reverse(answers.begin(), answers.end());
	for (int i = 0; i <= n; ++i) {
		printf("%s%d", (i == 0 ? "" : " "), answers[i]);
	}
	return 0;
}