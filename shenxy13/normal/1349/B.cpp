#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, k;
		scanf("%d %d", &n, &k);
		int a[n];
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		vector<int> pos;
		for (int i = 0; i < n; ++i) {
			if (a[i] == k) pos.push_back(i);
		}
		if (pos.size() == n) printf("yes\n");
		else if (pos.size() != 0) {
			pos.clear();
			for (int i = 0; i < n; ++i) {
				if (a[i] >= k) pos.push_back(i);
			}
			for (int i = 1; i < pos.size(); ++i) {
				if (pos[i] == pos[i - 1] + 1 || pos[i] == pos[i - 1] + 2) {
					printf("yes\n");
					goto hell;
				}
			}
			printf("no\n");
			hell:;
		} else printf("no\n");
	}
}