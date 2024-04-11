#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long ll;

int minReqd[MAX + 1] = {0};
int ckv[MAX] = {0};

int main() {
	for (int i = 0; i <= MAX; ++i) {
		minReqd[i] = 1000000;
	}
	minReqd[0] = 0;
	for (int i = 1; i <= MAX; ++i) {
		for (ll k = 2; k * (k-1) / 2 <= i; ++k) {
			ll cVal = k * (k-1) / 2;
			int pVal = minReqd[i - cVal] + 1;
			if (pVal <= minReqd[i]) {
				minReqd[i] = pVal;
				ckv[i] = k;
			}
		}
	}
	int n; scanf("%d", &n);
	if (n == 0) {
		printf("z\n");
		return 0;
	}
	vector<int> charCts;
	while (n > 0) {
		charCts.push_back(ckv[n]);
		n -= (ll)ckv[n] * (ckv[n] - 1) / 2;
	}
	char c = 'a';
	for (int ct : charCts) {
		for (int i = 0; i < ct; ++i) {
			printf("%c", c);
		}
		++c;
	}
	printf("\n");
	return 0;
}