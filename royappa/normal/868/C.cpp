#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n, k;
	cin >> n >> k;

	// if two questinos are known to exactly the same teams there is no point in adding both of them
	// because that will just add to the "known" count of each team. So one team's "known count" would go from (x/y) to (x+1)/(y+1)
	int numTypes = 1<<k;
	vector<int> types(numTypes, 0);
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			t |= x<<j; // question type is a mask of which teams know it. There are 2^k question types
		}
		types[t] = 1;
	}

	// check every subset of questions to see if it works
	for (int subset = 1; subset < (1<<numTypes); subset++) {
		bool can = true; // check if this potential subset of question types exists
		for (int i = 0; i < numTypes; i++) {
			if ((subset&(1<<i)) && types[i] == 0) {
				can = false;
				break;
			}
		}
		if (can) {// every question-type in this subset is present in the original data
			vector<int> h(k, 0); // for this subset, count how many questions each team knows
			for (int i = 0; i < numTypes; i++) {
				if (subset&(1<<i)) {
					// question i is part of chosen subset
					for (int j = 0; j < k; j++) {
						if (i&(1<<j)) { // team j knows question i
							h[j]++;
						}
					}
				}
			}
			int tot = __builtin_popcount(subset); // total number of questions in subset
			bool anyKnowsHalf = false;
			for (int j = 0; j < k; j++) {
				if (h[j] > tot/2) {
					anyKnowsHalf = true; // team j knows MORE than half
				}
			}
			if (!anyKnowsHalf) { // no team knows more than half, so this is a good subset
				cout << "YES" << endl;
				exit(0);
			}
		}
	}
	cout << "NO" << endl;
	exit(0);
}