#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 1000010;

char strng[NMAX], interp[NMAX * 2];
char restr1[NMAX], restr2[NMAX];
int palSpan[NMAX * 2];

void solve(char *strng, char *result) {
	int n = strlen(strng);
	for (int i = 0; i < 2 * n; i += 2) {
		interp[i] = strng[i/2];
		if (i + 1 < 2 * n - 1) interp[i + 1] = '.';
	}
	interp[2 * n - 1] = 0;
	int farCenter = 0;
	palSpan[0] = 0;
	for (int i = 1; i < 2 * n - 1; ++i) {
		int rightBound = farCenter + palSpan[farCenter];
		bool attemptExtend = true;
		if (i > rightBound) {
			palSpan[i] = 0;
			farCenter = i;
		} else {
			int im = 2 * farCenter - i;
			if (im - palSpan[im] < farCenter - palSpan[farCenter]) {
				attemptExtend = false;
				palSpan[i] = rightBound - i;
			} else {
				palSpan[i] = palSpan[im];
			}
		}
		while (i + palSpan[i] + 1 < 2 * n - 1 && i - palSpan[i] - 1 >= 0 &&
			interp[i + palSpan[i] + 1] == interp[i - palSpan[i] - 1]) ++palSpan[i];
		if (i + palSpan[i] > rightBound) farCenter = i;
//		printf("%d spans %d\n", i, palSpan[i]);
	}
//	printf("interp str %s\n", interp);
	// once manacher's has finished computation,
	// find the idx where the longest permutation should begin
	int overlapPoint = 0;
	while (overlapPoint < 2 * n - 1 && interp[overlapPoint] == interp[2 * n - 2 - overlapPoint]) ++overlapPoint;
	if (overlapPoint == 2 * n - 1) {
		strcpy(result, strng);
		return;
	}
//	printf("opt %d\n", overlapPoint);
	int bestLen = 0, bestCenter = -1;
	for (int i = 0; i < 2 * n - 1; ++i) {
		int palStart = i - palSpan[i];
		if (palStart > overlapPoint || i + palSpan[i] > (2 * n - 2 - palStart)) continue;
//		printf("%d p valid center\n", i);
		int totalLen = (i + palSpan[i] + 1) + palStart;
		if (totalLen > bestLen) {
			bestLen = totalLen;
			bestCenter = i;
		}
	}
	for (int i = 0; i < 2 * n - 1; ++i) {
		if (i <= bestCenter + palSpan[bestCenter] || 2 * n - 2 - i < bestCenter - palSpan[bestCenter] ) {
			if (interp[i] != '.') *(result++) = interp[i];
		}
	}
	*result = 0;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", strng);
		int n = strlen(strng);
		solve(strng, restr1);
		for (int i = 0, j = n - 1; i < j; ++i, --j) swap(strng[i], strng[j]);
		solve(strng, restr2);
//		printf("ANS %s\nVS %s\n", restr1, restr2);
		if (strlen(restr1) > strlen(restr2)) printf("%s\n", restr1);
		else printf("%s\n", restr2);
	}
	return 0;
}