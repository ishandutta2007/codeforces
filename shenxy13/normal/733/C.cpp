#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n, k;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	scanf("%d", &k);
	int b[k];
	for (int i = 0; i < k; ++i) scanf("%d", &b[i]);
	int ptr = 0;
	if (n == k) {
		bool pass = true;
		for (int i = 0; i < n; ++i) {
			if (a[i] != b[i]) pass = false;
		}
		printf(pass ? "YES" : "NO");
		return 0;
	}
	string ans[n - k];
	int x = 0, del = 1;
	for (int i = 0; i < k; ++i) {
		int sum = 0, mw = 0, s = ptr;
		while (ptr < n && sum < b[i]) {
			if (a[ptr] >= mw) mw = a[ptr];
			sum += a[ptr++];
		}
		if (sum != b[i]) {
			printf("NO");
			return 0;
		} else {
			int mptr = 0;
			bool goleft, fail = true;
			for (int i = s; i < ptr; ++i) {
				if (a[i] != mw) {
					fail = false;
					if (i != s) mptr = i - 1, goleft = false;
					break;
				}
			}
			if (!fail && mptr == 0) {
				goleft = true;
				for (int i = s; i < ptr; ++i) {
					if (a[i] == mw) {
						mptr = i;
						break;
					}
				}
			}
			if (s == ptr - 1) continue;
			else if (fail) {
				printf("NO");
				return 0;
			} else if (!goleft) {
				for (int i = mptr + 1; i < ptr; ++i) ans[x++] = to_string(mptr + del) + " R";
				for (int i = mptr; i > s; --i) ans[x++] = to_string(mptr + del) + " L", --del;
				del -= ptr - mptr - 1;
			} else {
				for (int i = mptr; i > s; --i) ans[x++] = to_string(mptr + del) + " L", --del;
				for (int i = mptr + 1; i < ptr; ++i) ans[x++] = to_string(mptr + del) + " R";
				del -= ptr - mptr - 1;
			}
		}
	}
	if (ptr != n) {
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for (int i = 0; i < n - k; ++i) printf("%s\n", ans[i].c_str());
	return 0;
}