#include <bits/stdc++.h>

using namespace std;

vector<int> digSet;

vector<int> firstHalf, fullSol, partSizes;

int occ[10];
char toOutput[10000][20];

int solCount = 0;

bool isValidInteger(int i, int j) {
	int val = 0;
	for (int k = i; k <= j; ++k) val = 10*val + fullSol[k];
	if (val >= 256) return false;
	if ((val > 0 && fullSol[i] == 0) || (val == 0 && (j - i > 0 && fullSol[i] == 0))) return false;
	return true;
}

void checkForPart(int i, int rem) {
	if (i > fullSol.size()) return;
	if (i == fullSol.size() && rem != 0) return;
	if (i == fullSol.size() && rem == 0) {
		int cChar = 0, cOutputChar = 0;;
		for (int b = 0; b < 4; ++b) {
			for (int x = 0; x < partSizes[b]; ++x) 
				toOutput[solCount][cOutputChar++] = '0' + fullSol[cChar++];
			if (b < 3) toOutput[solCount][cOutputChar++] = '.';
		}
		++solCount;
	} else {
		for (int k = 0; k < 3; ++k) {
			if (i + k < fullSol.size() && isValidInteger(i, i+k)) {
				partSizes.push_back(k + 1);
				checkForPart(i+k+1, rem-1);
				partSizes.pop_back();
			}
		}
	}
}

void findSol(int half) {
	if (half == 0) {
		// check if this is a valid sol
		// printf("checking palindrome:\n");
		// for (int k : firstHalf) printf("%d", k);
		// printf("\n");
		for (int d : digSet) if (occ[d] == 0) return;
		fullSol = firstHalf;
		for (int k = fullSol.size() - 1; k >= 0; --k) fullSol.push_back(firstHalf[k]);
		checkForPart(0, 4);
		fullSol = firstHalf;
		for (int k = fullSol.size() - 2; k >= 0; --k) fullSol.push_back(firstHalf[k]);
		checkForPart(0, 4);
	} else {
		for (int d : digSet) {
			firstHalf.push_back(d); ++occ[d];
			findSol(half - 1);
			firstHalf.pop_back(); --occ[d];
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int k = 0; k < n; ++k) {
		int x; scanf("%d", &x); digSet.push_back(x);
	}
	for (int len = 2; len <= 6; ++len) {
		findSol(len);
	}
	printf("%d\n", solCount);
	for (int i = 0; i < solCount; ++i) printf("%s\n", toOutput[i]);
	return 0;
}