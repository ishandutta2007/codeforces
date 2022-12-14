#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, k;
		scanf("%d %d", &n, &k);
		k = n / 2 - k + 1;
		char seq[n], tseq[n];
		for (int i = 0; i < n; ++i) scanf(" %c", &seq[i]);
		for (int i = 0; i < k; ++i) tseq[i] = '(';
		for (int i = k; i < 2 * k; ++i) tseq[i] = ')';
		for (int i = 2 * k; i < n; ++i) {
			if (i % 2) tseq[i] = ')';
			else tseq[i] = '(';
		}
		vector<ii> ans;
		for (int i = 0; i < n; ++i) {
			if (seq[i] == tseq[i]) continue;
			int j;
			for (j = i + 1; seq[j] != tseq[i]; ++j);
			ans.push_back(ii(i + 1, j + 1));
			reverse(seq + i, seq + j + 1);
		}
		printf("%lu\n", ans.size());
		for (ii i: ans) printf("%d %d\n", i.first, i.second);
	}
	return 0;
}