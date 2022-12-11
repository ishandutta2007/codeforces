#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<int> p0xbi; 
vector<int> pixb0;
int n;

int askQuery(int i, int j) {
	return pixb0[i] ^ p0xbi[0] ^ p0xbi[j];
}

bool isPermutation(vector<int> &a) {
	if (a.size() != n) {
		return false;
	}
	vector<int> ct(n, 0);
	for (int i = 0; i < n; ++i) {
		if (a[i] < 0 || a[i] >= n) {
			return false;
		} else {
			++ct[a[i]];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ct[i] == 0) {
			return false;
		}
	}
	return true;
}

bool areInverses(vector<int> &p, vector<int> &b) {
	if (!isPermutation(p) || !isPermutation(b)) {
		return false;
	} else {
		for (int i = 0; i < n; ++i) {
			if (p[b[i]] != i) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	cin >> n;
	p0xbi = vector<int>(n, 0);
	pixb0 = vector<int>(n, 0);
	for (int i = 0; i < n; ++i) {
		cout << "? " << 0 << " " << i << endl;
		cin >> p0xbi[i];
		cout << "? " << i << " " << 0 << endl;
		cin >> pixb0[i];
	}

	vector<int> equalPs(n, 0);
	vector<int> equalBs(n, 0);

	int ptr = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (askQuery(i, j) == 0) {
				equalPs[ptr] = i;
				equalBs[ptr] = j;
				++ptr;
			}
		}
	}

	vector<int> finalP(0, 0);
	int valids = 0;

	for (int v = 0; v < n; ++v) {
		// p_equalPs[v] = b_equalBs[v] = 0
		int zeroInP = equalPs[v];
		int zeroInB = equalBs[v];
		vector<int> posP(n, 0);
		vector<int> posB(n, 0);
		posP[zeroInP] = 1;
		posB[zeroInB] = 1;
		for (int i = 0; i < n; ++i) {
			posP[i] = askQuery(i, zeroInB);
			posB[i] = askQuery(zeroInP, i);
		}

		if (areInverses(posP, posB)) {
			++valids;
			if (finalP.size() == 0) {
				finalP = posP;
			}
		}
	}

	cout << "!" << endl;
	cout << valids << endl;
	for (int i = 0; i < n; ++i) {
		cout << (i > 0 ? " " : "") << finalP[i];
	}
	cout << endl;

	return 0;
}