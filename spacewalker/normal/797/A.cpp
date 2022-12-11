#include <cstdio>
#include <vector>
#define MAX 100000

using namespace std;

int pFac[MAX + 1] = {0};

void initPFac() {

	for (int i = 2; i <= MAX; ++i) {
		pFac[i] = i;
	}

	pFac[0] = 1;
	pFac[1] = 1;
	for (int i = 2; i <= MAX; ++i) {
		if (pFac[i] < i) {
			continue;
		}
		for (int toMark = 2 * i; toMark <= MAX; toMark += i) {
			pFac[toMark] = i;
		}
	}
}

void printVector(vector<int> vs) {
	for (int i = 0; i < vs.size(); ++i) {
		printf("%s%d", (i > 0 ? " " : ""), vs[i]);
	}
}

int main() {

	initPFac();

	int n, k; scanf("%d %d", &n, &k);
	vector<int> factors;
	int c = n;
	while (c > 1) {
		factors.push_back(pFac[c]);
		c /= pFac[c];
	}

	if (factors.size() < k) {
		printf("-1\n");
		return 0;
	}
	int FL = factors.size();
	vector<int> realFList;
	int first = 1;
	for (int i = 0; i < FL - k + 1; ++i) {
		first *= factors[i];
	}
	realFList.push_back(first);
	for (int rest = FL - k + 1; rest < FL; ++rest) {
		realFList.push_back(factors[rest]);
	}

	printVector(realFList);

	return 0;
}