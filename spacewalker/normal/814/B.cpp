#include <cstdio>
#include <vector>

using namespace std;

vector<int> readVectorm1(int length) {
	vector<int> res(length, 0);
	for (int i = 0; i < length; ++i) {
		scanf("%d", &res[i]);
		--res[i];
	}
	return res;
}

void printVector(vector<int> &a) {
	for (int i = 0; i < a.size(); ++i) {
		printf("%s%d", (i == 0 ? "" : " "), a[i] + 1);
	}
}

bool validSol(vector<int> &a, vector<int> &s) {
	bool mismatched = false;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != s[i]) {
			if (mismatched) {
				return false; 
			} else {
				mismatched = true;
			}
		}
	}
	return true;
}

int main() {
	int n; scanf("%d", &n);
	vector<int> a = readVectorm1(n);
	vector<int> b = readVectorm1(n);

	vector<bool> inMatch(n, false);
	int matched = 0;

	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i]) {
			inMatch[a[i]] = true;
			++matched;
		}
	}

	if (matched == n - 1) {
		int nonMatch = 0;
		vector<int> ans(n, 0);
		for (int i = 0; i < n; ++i) {
			if (!inMatch[i]) {
				nonMatch = i;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] == b[i]) {
				ans[i] = a[i];
			} else {
				ans[i] = nonMatch;
			}
		}

		printVector(ans);
	} else {
		int toFill1 = -1;
		int toFill2 = -1;
		int fidx1 = -1;
		int fidx2 = -1;
		vector<int> ans(n, 0);

		for (int i = 0; i < n; ++i) {
			if (!inMatch[i]) {
				if (toFill1 == -1) {
					toFill1 = i;
				} else {
					toFill2 = i;
				}
			} 
			if (a[i] != b[i]) {
				if (fidx1 == -1) {
					fidx1 = i;
				} else {
					fidx2 = i;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			if (a[i] == b[i]) {
				ans[i] = a[i];
			}
		}

		ans[fidx1] = toFill1;
		ans[fidx2] = toFill2;
		if (validSol(a, ans) && validSol(b, ans)) {
			printVector(ans);
		} else {
			ans[fidx2] = toFill1;
			ans[fidx1] = toFill2;
			printVector(ans);
		}
	}
	return 0;
}