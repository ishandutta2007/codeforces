#include <iostream>
#include <vector>
#include <algorithm>
#define NMAX 100001
#define INF 1000000000
#define NEWNUMMAX 2000000
using namespace std;

int main() {
	//printf("starting...\n");
	vector<vector<int>> divList(NMAX + 1, vector<int>());
	for (int i = 1; i <= NMAX; ++i) {
		for (int toMark = i; toMark <= NMAX; toMark += i) {
			divList[toMark].push_back(i);
		}
	}
	//printf("done w/precalc\n");
	int n; scanf("%d", &n);
	vector<int> a(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	vector<vector<int>> idxDivBy(NMAX + 1, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int div : divList[a[i]]) {
			idxDivBy[div].push_back(i);
		}
	}
	//printf("is here\n");
	int earliestPairElem = INF;
	for (int cdiv = 2; cdiv <= NMAX; ++cdiv) {
		if (idxDivBy[cdiv].size() >= 2) {
			//printf("checking divisor %d\n", cdiv);
			sort(idxDivBy[cdiv].begin(), idxDivBy[cdiv].end());
			earliestPairElem = min(earliestPairElem, idxDivBy[cdiv][1]);
		}
	}
	//printf("epe is %d\n", earliestPairElem);
	if (earliestPairElem == INF) {
		for (int i = 0; i < n; ++i) {
			printf("%s%d", (i == 0 ? "" : " "), a[i]);
		}
	} else {
		vector<bool> isPrime(NEWNUMMAX + 1, true);
		isPrime[0] = false;
		isPrime[1] = false;
		for (int i = 2; i <= NEWNUMMAX; ++i) {
			if (isPrime[i]) {
				for (int toMark = 2*i; toMark <= NEWNUMMAX; toMark += i) {
					isPrime[toMark] = false;
				}
			}
		}
		for (int i = 0; i < earliestPairElem; ++i) {
			for (int div : divList[a[i]]) {
				isPrime[div] = false;
			}
		}
		int smallestUntaken = -1;
		for (int i = 0; i <= NEWNUMMAX; ++i) {
			if (isPrime[i]) {
				smallestUntaken = i;
				break;
			}
		}
		vector<int> ans(a);
		// case 1:
		if (smallestUntaken > a[earliestPairElem]) {
			// we fill as normal
			for (int toFill = earliestPairElem; toFill < n; ++toFill) {
				ans[toFill] = smallestUntaken;
				isPrime[smallestUntaken] = false;
				while (!isPrime[smallestUntaken]) {
					++smallestUntaken;
				}
			}
		} else {
			// case 2:
			// we fill epe manually, then proceed
			vector<bool> isTaken(2*NMAX, false);
			vector<int> factors;
			for (int i = 0; i < earliestPairElem; ++i) {
				for (int div : divList[a[i]]) {
					if (div >= 2) {
						factors.push_back(div);
					}
				}
			}
			for (int f : factors) {
				/*if (isTaken[f]) {
					continue;
				}*/
				for (int toMark = f; toMark <= 2*NMAX; toMark += f) {
					isTaken[toMark] = true;
				}
			}
			for (int cand = a[earliestPairElem] + 1; cand <= NEWNUMMAX; ++cand) {
				if (!isTaken[cand]) {
					ans[earliestPairElem] = cand;
					break;
				}
			}
			for (int div : divList[ans[earliestPairElem]]) {
				isPrime[div] = false;
			}
			for (int toMark = ans[earliestPairElem]; toMark <= NEWNUMMAX; toMark += ans[earliestPairElem]) {
				isPrime[toMark] = false;
			}
			int smallestUntaken2 = -1;
			for (int i = 0; i <= NEWNUMMAX; ++i) {
				if (isPrime[i]) {
					smallestUntaken2 = i;
					break;
				}
			}
			for (int toFill = earliestPairElem + 1; toFill < n; ++toFill) {
				ans[toFill] = smallestUntaken2;
				isPrime[smallestUntaken2] = false;
				while (!isPrime[smallestUntaken2]) {
					++smallestUntaken2;
				}
			}
		}
			for (int i = 0; i < n; ++i) {
				printf("%s%d", (i == 0 ? "" : " "), ans[i]);
			}
	}
	return 0;
}