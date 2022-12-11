#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class staticrsq {
	vector<int> partials;
public:
	staticrsq(vector<int> orig) : partials(orig.size() + 1, 0) {
		for (int i = 0; i < orig.size(); ++i) {
			partials[i+1] = partials[i] + orig[i];
		}
	}
	int query(int i, int j) {
		return (i <= j ? 0 : partials[j + 1] - partials[i]);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	string garland; cin >> garland;/*
	vector<staticrsq> negateRep;
	for (int i = 0; i < 26; ++i) {
		vector<int> negation(n, 1);
		for (int i = 0; i < )
	}*/

	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int toChange; char koyomi; cin >> toChange >> koyomi;
		int left = n - 1;
		int right = n - 1;
		int changesLeft = toChange;
		for (int i = n - 1; i >= 0; --i) {
			if (garland[i] != koyomi) {
				--toChange;
			}
			left = i;
			if (toChange == 0) {
				break;
			}
		}

		//cout << "left endpt of initial interval is " << left << endl;

		if (left == 0) {
			cout << n << endl;
			continue;
		}

		int maxPoints = right - left + 1;

		for (int cleft = left - 1; cleft >= 0; --cleft) {
			if (garland[cleft] == koyomi) {
				// we get this character for free!
				maxPoints = max(maxPoints, right - cleft + 1);
			} else {
				// slide back until we get a non-match

				if (garland[right] != koyomi) {
					--right;
				} else {
					while (garland[right] == koyomi && cleft <= right) {
						--right;
					}
					--right;
				}

				maxPoints = max(maxPoints, right - cleft + 1);
			}
			//cout << "interval endpoints: " << cleft << " " << right << endl;
		}

		cout << maxPoints << endl;
	}

	return 0;
}