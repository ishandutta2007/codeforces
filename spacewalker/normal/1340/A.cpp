#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> perm(n);
		for (int i = 0; i < n; ++i) scanf("%d", &perm[i]);
		for (int i = 0; i < n; ++i) --perm[i];
		vector<int> placeInPerm(n);
		for (int i = 0; i < n; ++i) placeInPerm[perm[i]] = i;
//		for (int i = 0; i < n; ++i) printf("pip %d %d\n", i, placeInPerm[i]);
		vector<int> breakps{0};
		for (int i = 1; i < n; ++i) {
			if (placeInPerm[i] < placeInPerm[i - 1]) breakps.push_back(i);
		}
		breakps.push_back(n);
//		for (int x : breakps) printf("breakpoint %d\n", x);
		for (int i = 0; i + 1 < breakps.size(); ++i) reverse(begin(placeInPerm) + breakps[i], begin(placeInPerm) + breakps[i+1]);
		bool isValid = true;
		for (int i = 1; i < n; ++i) if (placeInPerm[i] > placeInPerm[i-1]) isValid = false;
		if (isValid) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}