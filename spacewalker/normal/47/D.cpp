#include <bits/stdc++.h>

using namespace std;

int n, m; // n is length, m is attempt count

char att[10][40];
int correct[10];

char cSol[40];

bool checkCSolValid() {
	for (int i = 0; i < m; ++i) {
		int ct = 0;
		for (int j = 0; j < n; ++j) {
			if (cSol[j] == att[i][j]) ++ct;
		}
		if (ct != correct[i]) return false;
	}
	return true;
}

// base the solution off of the first attempt
int attSolve(int i, int cct) {
	// printf("call %d %d %s\n", i, cct, cSol);
	if (cct > correct[0] || (i == n && cct != correct[0])) return 0;
	else if (i == n && cct == correct[0]) {
		// printf("testsel %s n %d cct %d\n", cSol, n, cct);
		return checkCSolValid();
	} else {
		// what if we got this one correct?
		cSol[i] = att[0][i];
		int part1 = attSolve(i + 1, cct + 1);
		cSol[i] = ('1' - cSol[i]) + '0'; // this basically flips it
		int part2 = attSolve(i + 1, cct);
		return part1 + part2;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) scanf("%s %d", att[i], correct + i);
	printf("%d\n", attSolve(0, 0));
	return 0;
}