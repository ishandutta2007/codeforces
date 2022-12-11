#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char inp[400010], ans[400010];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s", inp);
	int letc[26] = {0};
	for (int i = 0; inp[i]; ++i) ++letc[inp[i] - 'a'];
	int delc[26] = {0};
	for (int i = 0; i < 26; ++i) {
		if (k > 0) {
			int roundDel = min(k, letc[i]);
			delc[i] = roundDel;
			k -= roundDel;

		}
	}
	for (int i = 0; inp[i]; ++i) {
		if (delc[inp[i] - 'a'] == 0) printf("%c", inp[i]);
		else --delc[inp[i] - 'a'];
	}
	printf("\n");
	return 0;
}