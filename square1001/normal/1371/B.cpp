#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int Q;
	cin >> Q;
	while (Q--) {
		int N, R;
		cin >> N >> R;
		if (R < N) {
			cout << 1LL * R * (R + 1) / 2 << endl;
		}
		else {
			cout << 1LL * N * (N - 1) / 2 + 1 << endl;
		}
	}
	return 0;
}