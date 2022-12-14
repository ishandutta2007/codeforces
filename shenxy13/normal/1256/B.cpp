#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
int main() {
	int q, n;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d", &n);
		deque<int> perm(n), ans;
		for (int j = 0; j < n; ++j) scanf("%d", &perm[j]);
		while (!perm.empty()) {
			deque<int>::iterator ptr = min_element(perm.begin(), perm.end());
			int k = ptr - perm.begin();
			ans.push_back(*ptr);
			perm.erase(ptr);
			for (int j = 0; j < k - 1; ++j) {
				ans.push_back(perm.front());
				perm.pop_front();
			}
		}
		for (int i: ans) printf("%d ", i);
		printf("\n");
	}
	return 0;
}