#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, s, mx = 0, ans, mptr;
		scanf("%d %d", &n, &s);
		int a[n];
		for (int j = 0; j < n; ++j) scanf("%d", &a[j]);
		int ptr = 0;
		while (ptr != n && s >= 0) {
			if (a[ptr] > mx) {
				mx = a[ptr];
				mptr = ptr + 1;
			}
			s -= a[ptr++];
		}
		ans = ptr;
		s += mx;
		while (ptr != n && s >= 0) s -= a[ptr++];
		if (ans < (s >= 0 ? n : ptr - 1)) printf("%d\n", mptr);
		else printf("0\n");
	}
}