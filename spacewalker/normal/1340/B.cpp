#include <bits/stdc++.h>

using namespace std;

int segmentRep[10] = {0x77, //0b01110111
					  0x24, //0b00100100
					  0x5D, //0b01011101
					  0x6D, //0b01101101
					  0x2E, //0b00101110
					  0x6B, //0b01101011
					  0x7B, //0b01111011
					  0x25, //0b00100101
					  0x7F, //0b01111111
					  0x6F, //0b01101111
};



int bitsToAdd(int c, int target) {
//	printf("c t %d %d\n", c, target);
	int ans = 0;
	for (int iter = 0; iter < 8; ++iter) {
//		printf("bit %d values %d %d\n", iter, c & 1, target & 1);
		if (target & 1) {
			if ((c & 1) == 0) ++ans;
		} else if ((c & 1) == 1) return 1000000;
		target /= 2;
		c /= 2;
	}
	return ans;
}

char scoreboardDigit[10];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> scoreRep(n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", scoreboardDigit);
		for (int k = 6; k >= 0; --k) scoreRep[i] = (scoreRep[i]) * 2 + (scoreboardDigit[k] - '0');
//		printf("READ DIGIT VALUE %d\n", scoreRep[i]);
	}
	vector<vector<bool>> pwedengMabuo(n + 1, vector<bool>(k + 1, false));
	pwedengMabuo[0][0] = true;
	reverse(begin(scoreRep), end(scoreRep));
	for (int i = 1; i <= n; ++i) {
		for (int segCount = 0; segCount <= k; ++segCount) {
			for (int targetDig = 0; targetDig < 10; ++targetDig) {
				int bta = bitsToAdd(scoreRep[i-1], segmentRep[targetDig]);
				if (bta > segCount) continue;
				if (pwedengMabuo[i-1][segCount - bta]) pwedengMabuo[i][segCount] = true;
//				if (pwedengMabuo[i][segCount]) printf("%d %d reachable through %d\n", i, segCount, targetDig);
			}
		}
	}
	if (!pwedengMabuo[n][k]) {
		printf("-1\n");
		return 0;
	}
	vector<int> ans;
	int csegCount = k;
	for (int i = n; i > 0; --i) {
		for (int targetDig = 9; targetDig >= 0; --targetDig) {
			int bta = bitsToAdd(scoreRep[i-1], segmentRep[targetDig]);
			if (bta > csegCount) continue;
			if (pwedengMabuo[i - 1][csegCount - bta]) {
				csegCount -= bta;
//				printf("moving to %d segs through %d\n", csegCount, targetDig);
				ans.push_back(targetDig);
				break;
			}
		}
	}
	for (int d : ans) printf("%d", d);
	printf("\n");
	return 0;
}