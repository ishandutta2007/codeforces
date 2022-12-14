#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, p10 = 1;
		scanf("%d", &n);
		vector<int> ans;
		while (n != 0) {
			if (n % 10) ans.push_back(n % 10 * p10);
			n /= 10;
			p10 *= 10;
		}
		printf("%lu\n", ans.size());
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d", ans[i]);
			if (i != ans.size() - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}