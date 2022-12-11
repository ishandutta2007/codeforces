#include <bits/stdc++.h>

using namespace std;

bool viableStart(vector<int> &pile, vector<int> &hand, int stopTake) {
	// take all the cards starting from before position i. does this lead to a good hand?
	int n = hand.size();
	vector<bool> inHand(n, false);
	for (int x : hand) {
		if (x > 0) {
			inHand[x - 1] = true;
		}
	}
	for (int i = 0; i < stopTake; ++i) {
		if (pile[i] > 0) {
			// printf("card %d starts at pp %d\n", pile[i] - 1, i);
			inHand[pile[i] - 1] = true;
		}
	}
	// printf("starting vs %d with cards: ", stopTake);
	// for (int i = 0; i < n; ++i) if (inHand[i]) printf("%d ", i);
	// printf("\n");
	// now simulate the 1 to n thing
	for (int i = stopTake, ctm = 1; ctm <= n; ++i, ++ctm) {
		if (!inHand[ctm - 1]) {
			// printf("expecting card %d\n", ctm - 1);
			return false;
		}
		// printf("card %d placed\n", ctm - 1);
		if (i < n && pile[i] > 0) {
			// printf("got card %d\n", 	 pile[i] - 1);
			inHand[pile[i] - 1] = true;
		}
	}
	return true;
}

// an auto win is a win where the first card we play is not 1.
// can we do it?
int attemptAutoWin(vector<int> &hand, vector<int> &pile) {
	int n = pile.size();
	vector<bool> inHand(n);
	for (int v : hand) {
		if (v > 0) inHand[v-1] = true;
	}
	if (inHand[0]) return -1;
	int onei = -1;
	for (int i = 0; i < n; ++i) {
		if (pile[i] == 1) onei = i;
	}
	// printf("one at pile index %d\n", onei);
	// check if the ones form a streak to the end
	int ctm, offset;
	for (offset = 0, ctm = 1; onei + offset < n; ++offset, ++ctm) {
		if (pile[onei + offset] != ctm) {
			// printf("expecting card %d at pos %d, got %d\n", ctm, onei + offset, pile[onei + offset]);
			return -1;
		}
	}
	// check if we can do the whole thing
	for (int ccard = ctm, pilePos = 0; ccard <= n; ccard++, pilePos++) {
		// printf("checking for %d\n", ccard);
		if (!inHand[ccard - 1]) {
			// printf("expecting %d in hand\n", ccard);
			return -1;
		}
		if (pile[pilePos] > 0) {
			// printf("added %d to hand\n", pile[pilePos] - 1);
			inHand[pile[pilePos] - 1] = true;
		}
	}
	return onei;
}

int main() {
	int n; scanf("%d", &n);
	vector<int> hand(n), pile(n);
	for (int i = 0; i < n; ++i) scanf("%d", &hand[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &pile[i]);
	int autoWinVal = attemptAutoWin(hand, pile);
	if (autoWinVal != -1) {
		printf("%d\n", autoWinVal);
		return 0;
	}
	int lo = 0;
	int hi = n;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (viableStart(pile, hand, mid)) hi = mid;
		else lo = mid + 1;
	}
	// printf("viable start pos %d\n", lo);
	printf("%d\n", lo + n);
	return 0;
}