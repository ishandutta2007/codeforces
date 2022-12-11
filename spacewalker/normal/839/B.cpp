#include <cstdio>
#include <vector>

using namespace std;
/*
22 A.BB 99
33 A.CC 88
44 ..DD 77
55 1111 66
*/
int main() {
	int n, k; scanf("%d %d", &n, &k);

	vector<int> grp(k, 0);
	int sumOfAll = 0;

	for (int i = 0; i < k; ++i) {
		int ai; scanf("%d", &ai);
		grp[i] = ai;
		sumOfAll += grp[i];
	}

	int quads = n;
	int doubles = 2*n;

	for (int i = 0; i < k; ++i){
		while (quads > 0 && grp[i] >= 4) {
			quads--;
			grp[i] -= 4;
		}
	}

	if (quads == 0) {
		// we are now purely assigning doubles
		// an n-group takes ceil(n/2) pairs.
		int pairNeeded = 0;
		for (int i = 0; i < k; ++i) {
			pairNeeded += grp[i]/2 + (grp[i] % 2 == 0 ? 0 : 1);
		}
		printf("%s\n", (pairNeeded <= doubles ? "yEs" : "nO"));
	} else {
		// we still have quads left over!
		// a quad can fit a 2 and 1, two 1s, or a 3.
		// also all groups are 1, 2, or 3-groups.
		int g1 = 0;
		int g2 = 0;
		int g3 = 0;
		for (int i = 0; i < k; ++i) {
			if (grp[i] == 1) {++g1;}
			else if (grp[i] == 2) {++g2;}
			else if (grp[i] == 3 && quads == 0) {++g3;}
			else if (grp[i] == 3) {--quads;}
		}
		if (quads == 0) {
			// we are at the double assignment thing again
			int pairNeeded = g1 + g2 + 2*g3;
			printf("%s\n", (pairNeeded <= doubles? "YeS" : "No"));
		} else {
			// we have quads, but no 3-groups left
			while (g1 > 0 && g2 > 0 && quads > 0) {
				--g1; --g2; --quads;
			}
			if (quads > 0) {
				if (g2 == 0) {
					int total = 2*quads + doubles;
					printf("%s\n", (total >= g1 ? "yes" : "no"));
				} else {
					// greedily assign doubles
					if (doubles >= g2) {
						printf("yeS");
						return 0;
					}
					int g2left = g2 - doubles; //printf("%d groups left to assign to %d quads\n", g2left, quads);
					int total = (quads % 2 == 0 ? 3*quads/2 : 3*(quads-1)/2 + 1);
					printf("%s\n", total >= g2left ? "Yes" : "No");
				}
			} else {
				// no quads. just 1 and 2s
				printf("%s\n", (g1 + g2 <= doubles ? "YES" : "NO"));
			}
		}
	}

	return 0;
}