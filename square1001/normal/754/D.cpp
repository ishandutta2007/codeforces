#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, l[300009], r[300009], cp[600009], deg[600009], bit[1048588]; vector<int> pr[600009];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l[i], &r[i]);
		cp[i] = l[i]; cp[i + n] = ++r[i];
	}
	sort(cp, cp + 2 * n);
	for (int i = 0; i < n; i++) {
		l[i] = lower_bound(cp, cp + 2 * n, l[i]) - cp;
		r[i] = lower_bound(cp, cp + 2 * n, r[i]) - cp;
		pr[r[i]].push_back(i); deg[l[i]]++;
	}
	int rl = 0, rr = 0;
	for (int i = 0; i < 2 * n; i++) {
		int sum = 0, ptr = 0;
		for (int j = 19; j >= 0; j--) {
			if (sum + bit[ptr + (1 << j)] < m) {
				ptr += 1 << j; sum += bit[ptr];
			}
		}
		if (ptr != 1048575 && cp[rr] - cp[rl] < cp[i] - cp[ptr]) {
			rr = i; rl = ptr;
		}
		for (int j = i + 1; j <= 1048576; j += j & (-j)) bit[j] += deg[i];
		for (int j : pr[i]) {
			for (int k = l[j] + 1; k <= 1048576; k += k & (-k)) bit[k]--;
		}
	}
	printf("%d\n", cp[rr] - cp[rl]);
	for (int i = 0, cnt = 0; i < n && cnt < m; i++) {
		if ((l[i] <= rl && rr <= r[i]) || cp[rl] == cp[rr]) printf("%d ", i + 1), cnt++;
	}
	return 0;
}