#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isThereNext[400][400];
// itn[i][j] = DTE some k = i (mod j) such that a[k] is a next position

int LIMIT;

void updateSqrtTable(int x, bool isNext) {
	if (!isNext) return;
	for (int i = LIMIT; i > 0; --i) {
		isThereNext[x%i][i] = true;
		// printf("%d %d THERE IS NEXT\n", x%i, i);
	}
}

int main() {
	int n; scanf("%d", &n);
	LIMIT = sqrt(n);
	// printf("LIMIT %d\n", LIMIT);
	vector<int> arr(n), placeInArr(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]); --arr[i];
		placeInArr[arr[i]] = i;
	}
	// cur positions and next positions:
	// cur means current player wins
	// next means next player wins
	// n is a next position
	// a position is a cur position iff you can reach some next position from it.
	vector<int> winner(n, 0); // 1 if cur, -1 if next, 0 if unfilled
	updateSqrtTable(placeInArr[n-1], true);
	winner[placeInArr[n-1]] = -1;
	for (int i = n-1; i > 0; --i) {
		// printf("processing elem %d\n", i-1);
		bool isThisNext = true;
		if (i > LIMIT) {
			// printf("doing manual lookup\n");
			for (int j = (placeInArr[i-1] % i); j < n; j += i) {
				// printf("check index %d\n", j);
				if (winner[j] == -1) {
					// printf("found next state %d\n", j);
					isThisNext = false;
					break;
				}
			}
		} else {
			// printf("doing table check: is there next %d %d\n", placeInArr[i-1]%i, i);
			isThisNext = !isThereNext[placeInArr[i-1]%i][i];
		}
		updateSqrtTable(placeInArr[i-1], isThisNext);
		if (isThisNext) winner[placeInArr[i-1]] = -1;
		else winner[placeInArr[i-1]] = 1;
		// printf("pos state %d\n", winner[placeInArr[i-1]]);
	}
	for (int i = 0; i < n; ++i) {
		if (winner[i] == 1) printf("A");
		else printf("B");
	}
	printf("\n");
	return 0;
}