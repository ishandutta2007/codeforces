#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int NMAX = 1010;

char strng[NMAX];
int farRight[NMAX];
int occs[100];
int charLimit[100];
int splitWays[NMAX];
int maxSubLen[NMAX];

int main() {
	int n; scanf("%d", &n);
	scanf("%s", strng);
	for (int i = 0; i < 26; ++i) scanf("%d", charLimit + i);
	for (int i = 0; i < n; ++i) {
		memset(occs, 0, sizeof occs);
		int maxLen = MOD;
		for (int j = i; j >= 0; --j) {
			maxLen = min(maxLen, charLimit[strng[j] - 'a']);
			if (maxLen < i - j + 1) break;
			else farRight[i] = j;
		}
//		printf("fr %d %d\n", i, farRight[i]);
	}
	splitWays[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = farRight[i]; j <= i; ++j) {
			splitWays[i + 1] = (splitWays[i + 1] + splitWays[j]) % MOD;
		}
	}
	maxSubLen[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = farRight[i]; j <= i; ++j) {
			maxSubLen[i + 1] = max(maxSubLen[i+1], max(maxSubLen[j], (i - j + 1)));
		}
//		printf("msl %d %d\n", i, maxSubLen[i + 1]);
	}
	int minSplit = 0;
	for (int cRight = n - 1; cRight >= 0; cRight = farRight[cRight] - 1) ++minSplit;
	printf("%d\n%d\n%d\n", splitWays[n], maxSubLen[n], minSplit);
	return 0;
}