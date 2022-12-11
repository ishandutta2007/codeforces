#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MOD 7

using namespace std;

int biases[] = {8169, 6189, 1689, 6891, 8691, 9168, 8196};

int inverses[] = {0, 1, 4, 5, 2, 3, 6};

int fmod(int i) {
	return ((i % MOD) + MOD) % MOD;
}

int main() {
	string s; cin >> s;
	int digits[10] = {};
	for (char c : s) {
		++digits[c - '0'];
	}
	--digits[1];
	--digits[6];
	--digits[8];
	--digits[9];
	vector<int> digSeq;
	int valOfNextPow = 1;
	int curVal = 0;
	for (int d = 0; d < 10; ++d) {
		for (int occ = 0; occ < digits[d]; ++occ) {
			//cout << "we have added " << digSeq.size() << " digits" << endl;
			//cout << "cv cs = " << curVal << " " << valOfNextPow << endl;
			//cout << "adding a " << d << endl;
			// add the digit
			digSeq.push_back(d);
			curVal = (curVal + (valOfNextPow * d) % MOD) % MOD;
			valOfNextPow = (valOfNextPow * 10) % MOD;
		}
	}
	//cout << "finished with cval = " << curVal << endl;
	//cout << "current shift = " << valOfNextPow << endl;
	// valOfNextPow * thingToAdd = -curVal
	int dexToAdd = fmod(-curVal * inverses[valOfNextPow]);
	cout << biases[dexToAdd];
	reverse(digSeq.begin(), digSeq.end());
	for (int c : digSeq) {
		cout << (char)(c + '0');
	}
	cout << endl;
	return 0;
}