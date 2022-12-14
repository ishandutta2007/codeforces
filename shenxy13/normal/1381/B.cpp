#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		int p[2 * n], pmax, idx = 0;
		for (int i = 0; i < 2 * n; ++i) scanf("%d", &p[i]);
		vector<int> sizes;
		pmax = p[0];
		for (int i = 1; i < 2 * n; ++i) {
			if (p[i] > pmax) {
				pmax = p[i];
				sizes.push_back(i - idx);
				idx = i;
			}
		}
		sizes.push_back(2 * n - idx);
		bitset<2001> bs;
		bs.reset();
		bs[0] = 1;
		for (int i: sizes) bs = bs | (bs << i);
		if (bs[n]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}