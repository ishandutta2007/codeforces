#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 1000010;

char longNum[NMAX];

ll prefModA[NMAX], sufModB[NMAX];

int main() {
	scanf("%s", longNum);
	int n = strlen(longNum);
	ll a, b; scanf("%lld %lld", &a, &b);
	prefModA[0] = (longNum[0] - '0') % a;
	for (int i = 1; i < n; ++i) prefModA[i] = (prefModA[i-1] * 10 + (longNum[i] - '0')) % a;
	sufModB[n-1] = (longNum[n-1] - '0') % b;
	for (ll i = n - 2, cpval = 10 % b; i >= 0; --i, cpval = (10 * cpval) % b) {
		sufModB[i] = (sufModB[i+1] + cpval * (longNum[i] - '0') % b) % b;
	}
	for (int i = 0; i + 1 < n; ++i) {
//		printf("%d p %lld s %lld\n", i, prefModA[i], sufModB[i]);
		if (prefModA[i] == 0 && sufModB[i + 1] == 0 && (longNum[i+1] != '0')) {
			printf("YES\n");
			for (int j = 0; j <= i; ++j) printf("%c", longNum[j]);
			printf("\n");
			for (int j = i + 1; j < n; ++j) printf("%c", longNum[j]);
			printf("\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}