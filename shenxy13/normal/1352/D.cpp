#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, mo = 0, al = 0, bo = 0, pa = 0, pb = 0;
		scanf("%d", &n);
		int a[n], l = 0, r = n - 1;
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		while (l <= r) {
			if (mo % 2) {
				pb = 0;
				while (pb <= pa && l <= r) pb += a[r--];
				bo += pb;
				++mo;
			} else {
				pa = 0;
				while (pa <= pb && l <= r) pa += a[l++];
				al += pa;
				++mo;
			}
		}
		printf("%d %d %d\n", mo, al, bo);
	}
	return 0;
}