#include <bits/stdc++.h>

using namespace std;

char str[1010];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	vector<int> ansf, ansb;
	for (int fp = 0, bp = n - 1; fp < bp; ++fp, --bp) {
		while (fp < n && str[fp] == ')') ++fp;
		while (bp >= 0 && str[bp] == '(') --bp;
//		printf("found pair %d %d\n", fp,  bp);
		if (fp < n && bp >= 0 && fp < bp) {
			ansf.push_back(fp);
			ansb.push_back(bp);
		}
	}
	reverse(ansb.begin(), ansb.end());
	if (ansf.size() == 0) {
		printf("0\n");
		return 0;
	}
	printf("1\n");
	printf("%lu\n", ansf.size() + ansb.size());
	for (int x : ansf) printf("%d ", x + 1);
	for (int x : ansb) printf("%d ", x + 1);
	return 0;
}