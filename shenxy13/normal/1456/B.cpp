#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main() {
	int n, ans = 1000000000;
	scanf("%d", &n);
	int a[n + 1], pxor[n + 1];
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	pxor[0] = 0;
	for (int i = 1; i <= n; ++i) pxor[i] = pxor[i - 1] ^ a[i];
	map<int, vector<int> > axor[30];
	vector<int> ones[30], zeroes[30];
	for (int i = 0; i <= n; ++i) {
		int recon = 0;
		for (int j = 29; j >= 0; --j) {
			vector<int> &v = axor[j][recon + (1 << j) - (pxor[i] & (1 << j))];
			int pos;
			if ((1 << j) & pxor[i]) pos = ones[j].empty() ? -1 : ones[j].back(), ones[j].push_back(i);
			else pos = zeroes[j].empty() ? -1 : zeroes[j].back(), zeroes[j].push_back(i);
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), pos);
			if (it != v.begin()) ans = min(ans, i - *--it);
			recon += pxor[i] & (1 << j);
			axor[j][recon].push_back(i);
		}
	}
	if (ans == 1000000000) printf("-1");
	else printf("%d", ans - 2);
	return 0;
}