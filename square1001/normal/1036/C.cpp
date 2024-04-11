#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const unsigned long long lim = 1000000000000000000;
vector<unsigned long long> v;
void enumerate(unsigned long long d, int c) {
	v.push_back(d);
	if (d * 10 <= lim) enumerate(d * 10, c);
	for (int i = 1; i <= 9; ++i) {
		if (d * 10 + i <= lim && c + 1 <= 3) {
			enumerate(d * 10 + i, c + 1);
		}
	}
}
int main() {
	for (int i = 1; i <= 9; ++i) {
		enumerate(i, 1);
	}
	sort(v.begin(), v.end());
	int Q;
	cin >> Q;
	while (Q--) {
		unsigned long long L, R;
		cin >> L >> R;
		cout << (lower_bound(v.begin(), v.end(), R + 1) - lower_bound(v.begin(), v.end(), L)) << endl;
	}
	return 0;
}