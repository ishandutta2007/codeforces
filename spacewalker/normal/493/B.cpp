#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n; cin >> n;

	int temp;
	vector<int> first, second;
	long long firstTotal = 0;
	long long secondTotal = 0;
	bool secondLast = false;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		if (temp < 0) {
			second.push_back(-temp);
			secondTotal -= temp;
			secondLast = true;
		} else {
			first.push_back(temp);
			firstTotal += temp;
			secondLast = false;
		}
	}

	if (firstTotal != secondTotal) {
		cout << (firstTotal > secondTotal ? "first" : "second");
	} else if (first != second) {
		cout << (first > second ? "first" : "second");
	} else {
		cout << (secondLast ? "second" : "first");
	}

	return 0;
}