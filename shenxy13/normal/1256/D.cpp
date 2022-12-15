#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int n;
		long long k;
		scanf("%d %lld", &n, &k);
		char c;
		queue<int> zeropos;
		vector<int> ans;
		for (int j = 0; j < n; ++j) {
			scanf(" %c", &c);
			if (c == '0') zeropos.push(j);
		}
		for (int j = 0; j < n; ++j) {
			if (!zeropos.empty() && zeropos.front() - ans.size() <= k) {
				k -= zeropos.front() - ans.size();
				ans.push_back(0);
				zeropos.pop();
				printf("0");
			} else {
				ans.push_back(1);
				printf("1");
			}
		}
		printf("\n");
	}
	return 0;
}