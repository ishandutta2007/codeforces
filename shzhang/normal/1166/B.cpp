#include <cstdio>

using namespace std;

int cnt[26];
char name[50];

const char* core[] = {"aeiou", "eioua", "iouae", "ouaei", "uaeio"};

int main()
{
	int k;
	scanf("%d", &k);
	for (int n = 5; n < k; n++) {
		if (k % n == 0) {
			int m = k / n;
			if (m < 5) continue;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					printf("%c", core[i%5][j%5]);
				}
			}
			return 0;
		}
	}
	printf("-1");
	return 0;
}