#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define BCT 22

using namespace std;

bool isSet(int n, int bix) {
	return ((n & (1 << bix)) > 0);
}

int oneCount(vector<int> &arr, int cbi, int left, int right) {
	// check for the earliest 1 bit
	if (!isSet(arr[right], cbi)) {
		return 0;
	}
	int lo = left;
	int hi = right;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		// if mid is zero, we can safely move to mid + 1
		// otherwise, play safe and do hi = mid
		if (isSet(arr[mid], cbi)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return right - lo + 1;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	set<int> farr;
	for (int i = 0; i < n; ++i) {
		int dummy; scanf("%d", &dummy);
		farr.insert(dummy);
	}
	vector<int> arr(farr.size(), 0);
	int ptr = 0;
	for (int ai : farr) {
		arr[ptr++] = ai;
	}
	n = arr.size();
	for (int i = 0; i < n; ++i) {
		for (int b = BCT; b >= 0; --b) {
			//printf("%c", (isSet(arr[i], b) ? '1' : '0'));
		}
		//printf("\n");
	}
	int cBitMask = 0;
	for (int q = 0; q < m; ++q) {
		int x; scanf("%d", &x);
		cBitMask ^= x;
		// now we look for the mex
		int ans = 0;
		int crl = 0;
		int crr = n - 1;
		//printf("bitmask = %d\n", cBitMask);
		for (int bit = BCT; bit >= 0; --bit) {
			//printf("checking %dth bit\n", bit);
			if (crl > crr) {
				break;
			}
			if (isSet(cBitMask, bit)) { // the bit is 1
				//printf("the current bitmask has 1\n");
				//printf("current range from %d to %d\n", crl, crr);
				// check for how many ones there are
				int leadOneCt = oneCount(arr, bit, crl, crr);
				int firstOneIdx = crr - leadOneCt + 1;
				// if there are  2^(bit) ones, then the mex is forced to have a 1
				// else, it can be a zero :-D
				// but we need to adjust ranges accdgly
				if (leadOneCt < (1 << bit)) {
					// there is some number missing from the ones... 
					crl = firstOneIdx;
				} else {
					// :-( we need to make the cbit a 1
					crr = firstOneIdx - 1;
					ans |= (1 << bit);
				}
			} else {
				//printf("the current bitmask has 0\n");
				//printf("current range from %d to %d\n", crl, crr);
				int leadOneCt = oneCount(arr, bit, crl, crr);
				int firstOneIdx = crr - leadOneCt + 1;
				//printf("first one is at %d\n", firstOneIdx);
				int zeroCt = crr - crl + 1 - leadOneCt;
				//printf("%d beginning with zero\n", zeroCt);
				if (zeroCt < (1 << (bit))) {
					crr = firstOneIdx - 1;
				} else {
					//printf("one addition forced\n");
					crl = firstOneIdx;
					ans |= (1 << bit);
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}