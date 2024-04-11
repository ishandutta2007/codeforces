#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const int maxL = 30;

char s[maxN][maxL];
int n;
int len[maxN];

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		gets(s[i]);
		len[i] = strlen(s[i]);
	}
	int res = 0;
	for (int i = 0; ; ++i) {
		bool good = true;
		for (int j = 0; j < n; ++j) {
			if (i >= len[j]) {
				good = false;
				break;
			}
			if (s[j][i] != s[0][i]) {
				good = false;
				break;
			}
		}
		if (!good) break;
		res = i + 1;
	}

	printf("%d\n", res);
	return 0;
}