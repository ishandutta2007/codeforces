#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		int a[n], b[n];
		for (int j = 0; j < n; ++j) scanf("%d", &a[j]);
		for (int j = 0; j < n; ++j) scanf("%d", &b[j]);
		int query = -1;
		for (int j = 0; j < n; ++j) {
			if (a[j] > b[j]) {
				printf("NO\n");
				goto hell;
			} else if (a[j] == b[j]) {
				if (query != -1) query = 1000000000;
			} else if (query == -1) query = b[j] - a[j];
			else if (query != b[j] - a[j]) {
				printf("NO\n");
				goto hell;
			}
		}
		printf("YES\n");
		hell:;
	}
	return 0;
}