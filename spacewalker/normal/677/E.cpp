#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#define MOD 1000000007

using namespace std;
typedef vector<vector<int>> vvi;
int n;


int modExp(int b, int e) {
	long long cb = b;
	int ce = e;
	int res = 1;
	while (ce > 0) {
		if (ce % 2 == 1) {
			res = (res * cb) % MOD;
		}
		ce /= 2;
		cb = (cb * cb) % MOD;
	}
	return res;
}

struct GridNum {
	int exp3, exp2;
	GridNum(int exptwo, int expthree) {
		exp2 = exptwo;
		exp3 = expthree;
	}
	bool is0() {
		return (exp2 < 0 && exp3 < 0);
	}
	GridNum operator* (GridNum other) {
		if (is0() || other.is0()) {
			return GridNum(-1, -1);
		} else {
			return GridNum(exp2 + other.exp2, exp3 + other.exp3);
		}
	}
	GridNum operator/(GridNum other) {
		if (other.is0() || is0()) {
			return GridNum(-1, -1);
		} else {
			return GridNum(exp2 - other.exp2, exp3 - other.exp3);
		}
	}
	int collapse() {
		if (is0()) {
			return 0;
		} else {
			return (int)((modExp(2, exp2) * (long long)modExp(3, exp3)) % MOD);
		}
	}
	double lnCollapse() {
		if (is0()) {
			return -1;
		} else {
			return exp2 * log(2) + exp3 * log(3);
		}
	}
	bool operator< (GridNum other) {
		return lnCollapse() < other.lnCollapse();
	}
	bool operator> (GridNum other) {
		return lnCollapse() > other.lnCollapse();
	}
};
typedef vector<vector<GridNum>> vvgn;

vvi maxDStraight(vvgn &grid) {
	vvi up = vector<vector<int>>(n, vector<int>(n , -1));
	vvi left(up);
	vvi right(up);
	vvi down(up);
	vvi finish(up);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			up[i][j] = (i == 0 || grid[i][j].is0() ? 
				-grid[i][j].is0() : up[i-1][j] + 1);
			left[i][j] = (j == 0 || grid[i][j].is0() ? 
				-grid[i][j].is0() : left[i][j-1] + 1);
			finish[i][j] = min(up[i][j], left[i][j]);
		}
	}

	for (int i = n-1; i >= 0; --i) {
		for (int j = n-1; j >= 0; --j) {
			down[i][j] = (i == n-1 || grid[i][j].is0() ?
				-grid[i][j].is0() : down[i+1][j] + 1);
			right[i][j] = (j == n-1 || grid[i][j].is0() ?
				-grid[i][j].is0() : right[i][j+1] + 1);
			finish[i][j] = min(min(finish[i][j], down[i][j]), right[i][j]);
		}
	}
	
	return finish; 
}


vvi maxDRotated(vvgn &grid) {
	vvi upleft = vvi(n, vector<int>(n, -1));
	vvi upright(upleft);
	vvi downleft(upleft);
	vvi downright(upleft);
	vvi finish(upleft);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0) {
				upleft[i][j] = -grid[i][j].is0();
				upright[i][j] = upleft[i][j];
			} else {
				upleft[i][j] = (j == 0 || grid[i][j].is0() ? 
					-grid[i][j].is0() : upleft[i-1][j-1] + 1);
				upright[i][j] = (j == n-1 || grid[i][j].is0() ?
					-grid[i][j].is0() : upright[i-1][j+1] + 1);
			}
			finish[i][j] = min(upleft[i][j], upright[i][j]);
		}
	}

	for (int i = n-1; i >= 0; --i) {
		for (int j = n-1; j>= 0; --j) {
			if (i == n-1) {
				downleft[i][j] = -grid[i][j].is0();
				downright[i][j] = downleft[i][j];
			} else {
				downleft[i][j] = (j == 0 || grid[i][j].is0() ?
					-grid[i][j].is0() : downleft[i+1][j-1] + 1);
				downright[i][j] = (j == n-1 || grid[i][j].is0() ?
					-grid[i][j].is0() : downright[i+1][j+1] + 1);
			}
			finish[i][j] = min(finish[i][j], min(downleft[i][j], downright[i][j]));
		}
	}
	return finish;
}

void debugVVGN(vvgn toD) {
	cout << "values of vvgn\n";
	for (int i = 0; i < toD.size(); ++i) {
		for (int j = 0; j < toD[i].size(); ++j) {
			cout << toD[i][j].collapse() << ' ';
		}
		cout << endl;
	}
}

int main() {
	string temp; cin >> n;
	vvgn grid(n, vector<GridNum>(n, GridNum(0, 0)));
	for (int line = 0; line < n; ++line) {
		cin >> temp;
		for (int pos = 0; pos < n; ++pos) {
			if (temp[pos] == '0') {
				grid[line][pos] = GridNum(-1, -1);
			} else {
				grid[line][pos] = GridNum(temp[pos] == '2', temp[pos] == '3');
			}
		}
	}

	vvi maxCrossD = maxDStraight(grid);

	vvi maxRotatedD = maxDRotated(grid);

	// finally, we can actually start coding the solution

	vvgn rowPartials(n+1, vector<GridNum>(n+1, GridNum(0, 0)));
	vvgn colPartials(n+1, vector<GridNum>(n+1, GridNum(0, 0)));

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0 || j == 0) {
				continue;
			} else if (grid[i-1][j-1].is0()) {
				rowPartials[i][j] = GridNum(0, 0);
				colPartials[i][j] = GridNum(0, 0);
			} else {
				rowPartials[i][j] = rowPartials[i][j-1] * grid[i-1][j-1];
				colPartials[i][j] = colPartials[i-1][j] * grid[i-1][j-1];
			}
		}
	}

	vvgn drDiagPartials(n+1, vector<GridNum>(n+1, GridNum(0, 0)));
	vvgn dlDiagPartials(n+1, vector<GridNum>(n+1, GridNum(0, 0)));

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == 0) {
				continue;
			}
			drDiagPartials[i][j] = (j == 0 || grid[i-1][j-1].is0() ? 
				GridNum(0, 0) : drDiagPartials[i-1][j-1] * grid[i-1][j-1]);
			dlDiagPartials[i][j] = (j == n || grid[i-1][j].is0() ?
				GridNum(0, 0) : dlDiagPartials[i-1][j+1] * grid[i-1][j]);
		}
	}

	//debugVVGN(dlDiagPartials);

	// the final hurrah of code: tally up the final solutions
	GridNum cMax = GridNum(-1, -1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// check the max cross

			if (grid[i][j].is0()) {continue;}

			int sMC = maxCrossD[i][j];
			GridNum rowProduct = rowPartials[i+1][j + sMC + 1] / rowPartials[i+1][j - sMC];
			GridNum colProduct = colPartials[i + sMC + 1][j+1] / colPartials[i - sMC][j+1];
			GridNum finalResult = rowProduct * colProduct / grid[i][j];

			//cout << i << ":" << j << " sMC = " << sMC << "; fR = " << finalResult.collapse() << endl;
			cMax = (finalResult > cMax ? finalResult : cMax);

			// now, check the rotated cross
			int sMRC = maxRotatedD[i][j];
			GridNum DRProduct = drDiagPartials[i + 1 + sMRC][j + 1 + sMRC] / drDiagPartials[i - sMRC][j - sMRC];
			GridNum DLProduct = dlDiagPartials[i + 1 + sMRC][j - sMRC] / dlDiagPartials[i - sMRC][j + sMRC + 1];
			finalResult = DRProduct * DLProduct / grid[i][j];

			//cout << i << ":" << j << " sMRC = " << sMRC << "; products = " << DRProduct.collapse() << " and " << DLProduct.collapse() << endl;

			cMax = (finalResult > cMax ? finalResult : cMax);			
		}
	}

	cout << cMax.collapse();
	return 0;
}