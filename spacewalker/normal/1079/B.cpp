#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char handle[200];

int main() {
	scanf("%s", handle);
	int n = strlen(handle);
	for (int i = n; i < 200; ++i) handle[i] = '*';
	for (int pRows = 1; pRows <= 5; ++pRows) {
		for (int pCols = 1; pCols <= 20; ++pCols) {
			if (pRows * pCols >= n) {
				int pos = 0;
				printf("%d %d\n", pRows, pCols);
				int astk = (pRows*pCols - n);
				for (int aRow = 0; aRow < pRows; ++aRow) {
					int cAsCount = astk/pRows + (aRow < astk%pRows ? 1 : 0);
					for (int aCol = 0; aCol < pCols; ++aCol) {
						if (aCol < cAsCount) printf("*");
						else printf("%c", handle[pos++]);
					}
					printf("\n");
				}
				return 0;
			}
		}
	}
	return 0;
}