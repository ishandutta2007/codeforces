#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> ans;

void getAns(int n, int fac) {
	if (n == 1) {
		ans.push_back(fac);
	} else if (n == 2) {
		ans.push_back(fac);
		ans.push_back(2*fac);
	} else if (n == 3) {
		ans.push_back(fac);
		ans.push_back(fac);
		ans.push_back(3*fac);
	} else {
		int evens = n/2;
		for (int i = 0; i < n - evens; ++i) {
			ans.push_back(fac);
		}
		getAns(evens, 2*fac);
	}
}

int main() {
	int n; scanf("%d", &n);
	getAns(n, 1);
	for (int i = 0; i < n; ++i) {
		printf("%s%d", (i == 0 ? "" : " "), ans[i]);
	}
	printf("\n");
	return 0;
}