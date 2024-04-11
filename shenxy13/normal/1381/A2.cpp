#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		char a[n], b[n];
		vector<int> moves;
		for (int i = 0; i < n; ++i) scanf(" %c", &a[i]);
		for (int i = 0; i < n; ++i) scanf(" %c", &b[i]);
		int lptr = 0, rptr = n - 1;
		for (int i = 1; i <= n; ++i) {
			if (i % 2) {
				if (a[lptr] == b[n - i]) moves.push_back(1);
				moves.push_back(n + 1 - i);
				++lptr;
			} else {
				if (a[rptr] != b[n - i]) moves.push_back(1);
				moves.push_back(n + 1 - i);
				--rptr;
			}
		}
		printf("%lu", moves.size());
		for (int i: moves) printf(" %d", i);
		printf("\n");
	}
	return 0;
}