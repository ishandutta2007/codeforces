#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

/*const int maxN = 100;
int winner[2][maxN][maxN][maxN][maxN];

int calc(int move, int xp, int yp, int xv, int yv) {
	if (winner[move][xp][yp][xv][yv] != -1) {
		return winner[move][xp][yp][xv][yv];
	}
	if (xp == 0 && yp == 0) {
		return 1;
	}
	if (xv == 0 && yv == 0) {
		return 2;
	}

	int &res = winner[move][xp][yp][xv][yv];
	if (move == 0) {
		bool canMove = false;
		if (xp > 0) {
			if ((xp - 1 != xv || yp != yv) && calc(1 - move, xp - 1, yp, xv, yv) == 1) {
				return res = 1;
			}
			if (xp - 1 != xv || yp != yv) {
				canMove = true;
			}
		}
		if (yp > 0) {
			if ((xp != xv || yp - 1 != yv) && calc(1 - move, xp, yp - 1, xv, yv) == 1) {
				return res = 1;
			}
			if (xp != xv || yp - 1 != yv) {
				canMove = true;
			}
		}
		if (!canMove && calc(1 - move, xp, yp, xv, yv) == 1) {
			return res = 1;
		}
	} else {
		bool canMove = false;
		if (xv > 0) {
			if ((xv - 1 != xp || yv != yp) && calc(1 - move, xp, yp, xv - 1, yv) == 2) {
				return res = 2;
			}
			if (xv - 1 != xp || yv != yp) {
				canMove = true;
			}
		}
		if (yv > 0) {
			if ((xv != xp || yv - 1 != yp) && calc(1 - move, xp, yp, xv, yv - 1) == 2) {
				return res = 2;
			}
			if (xv != xp || yv - 1 != yp) {
				canMove = true;
			}
		}
		if (xv > 0 && yv > 0) {
			if ((xv - 1 != xp || yv - 1 != yp) && calc(1 - move, xp, yp, xv - 1, yv - 1) == 2) {
				return res = 2;
			}
			if (xv - 1 != xp || yv - 1 != yp) {
				canMove = true;
			}
		}
		if (!canMove && calc(1 - move, xp, yp, xv, yv) == 2) {
			return res = 2;
		}
	}

	return winner[move][xp][yp][xv][yv] = (1 - move) + 1;
}*/

int trivial(int xp, int yp, int xv, int yv) {
	int A = xp + yp;
	int B = max(xv, yv);

	if (xp < xv && yp <= yv) {
		return 1;
	}
	if (yp < yv && xp <= xv) {
		return 1;
	}
	if (A <= B) {
		return 1;
	} else {
		return 2;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//memset(winner, -1, sizeof(winner));
	int xp, yp, xv, yv;
	cin >> xp >> yp >> xv >> yv;
	int res = trivial(xp, yp, xv, yv);
	if (res == 1) {
		cout << "Polycarp" << endl;
	} else {
		cout << "Vasiliy" << endl;
	}

	/*const int maxN = 100;
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			for (int k = 0; k < maxN; ++k) {
				for (int l = 0; l < maxN; ++l) {
					if (i == k && j == l) {
						continue;
					}
					
					if (calc(0, i, j, k, l) != trivial(i, j, k, l)) {
						cout << i << " " << j << " " << k << " " << l << endl;
						cerr << "BAD!!!" << endl;
						cout << calc(0, i, j, k, l) << endl;
						cout << trivial(i, j, k, l) << endl;
						//return 0;
					}
				}
			}
		}
	}*/

	return 0;
}