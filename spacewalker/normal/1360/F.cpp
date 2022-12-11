#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 12;

char strList[NMAX][NMAX];
char testStr[NMAX];

int n, m; 

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		memset(strList, 0, sizeof strList);
		memset(testStr, 0, sizeof testStr);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", strList[i]);
		}
		bool printAnswer = false;
		for (int changePos = 0; changePos < m; ++changePos) {
			for (char tryc = 'a'; tryc <= 'z'; ++tryc) {
				for (int i = 0; i < m; ++i) testStr[i] = strList[0][i];
				testStr[changePos] = tryc;
				bool allStringsGood = true;
				for (int strComp = 0; strComp < n; ++strComp) {
					int differentPos = 0;
					for (int i = 0; i < m; ++i) if (testStr[i] != strList[strComp][i]) ++differentPos;
					if (differentPos > 1) allStringsGood = false;
				}
				if (allStringsGood) {
					printAnswer = true;
					break;
				}
			}
			if (printAnswer) break;
		}
		if (printAnswer) printf("%s\n", testStr);
		else printf("-1\n");
	}
	return 0;
}