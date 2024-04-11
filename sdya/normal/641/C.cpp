#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct Group {
	int shift;
	int start;
	Group() {
		start = 0;
		shift = 0;
	}
};

const int maxN = 1100000;
int p[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, q;
	Group A, B;
	scanf("%d%d", &n, &q);
	A.shift = 0;
	A.start = 0;
	B.shift = 1;
	B.start = 1;
	/*vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = i;
	}*/
	for (int i = 0; i < q; ++i) {
		int mode;
		scanf("%d", &mode);

		if (mode == 2) {
			if (A.shift % 2 == 0) {
				A.shift = (A.shift + 1) % n;
				B.shift = (B.shift - 1) % n;
			} else {
				A.shift = (A.shift - 1) % n;
				B.shift = (B.shift + 1) % n;
			}

			/*for (int i = 0; i < n; i += 2) {
				swap(a[i], a[i + 1]);
			}*/
		} else {
			int x;
			scanf("%d", &x);
			A.shift = (A.shift + x) % n;
			B.shift = (B.shift + x) % n;

			/*vector < int > b(n);
			for (int i = 0; i < n; ++i) {
				b[((i + x) % n + n) % n] = a[i];
			}
			a = b;*/
		}
	}

	A.shift = (A.shift % n + n) % n;
	B.shift = (B.shift % n + n) % n;

	for (int i = A.shift, j = 0; j < n / 2; ++j, i += 2, A.start += 2) {
		p[i % n] = A.start + 1;
	}
	for (int i = B.shift, j = 0; j < n / 2; ++j, i += 2, B.start += 2) {
		p[i % n] = B.start + 1;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", p[i]);
	}
	printf("\n");

	/*for (int i = 0; i < n; ++i) {
		printf("%d ", a[i] + 1);
	}
	printf("\n");*/

	return 0;
}