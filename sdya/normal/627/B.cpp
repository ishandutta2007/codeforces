#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxL = 500000;
long long ta[maxL], tb[maxL];

void update(long long t[], int k, long long delta) {
	for (int i = k; i < maxL; i |= (i + 1)) {
		t[i] += delta;
	}
}

long long get(long long t[], int k) {
	long long res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}
	return res;
}

long long get(long long t[], int l, int r) {
	if (l > r) {
		return 0;
	}
	return get(t, r) - get(t, l - 1);
}

long long va[maxL], vb[maxL];
int n, k, a, b, q;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
	for (int i = 0; i < q; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 1) {
			int d, value;
			scanf("%d%d", &d, &value);
			{
				long long oldValue = va[d];
				long long newValue = min((long long)(a), va[d] + value);
				va[d] = newValue;
				update(ta, d, newValue - oldValue);
			}
			{
				long long oldValue = vb[d];
				long long newValue = min((long long)(b), vb[d] + value);
				vb[d] = newValue;
				update(tb, d, newValue - oldValue);
			}
		} else {
			int l;
			scanf("%d", &l);
			int r = l + k - 1;
			long long res = get(tb, 1, l - 1) + get(ta, r + 1, maxL - 1);
			printf("%I64d\n", res);
		}
	}

	return 0;
}