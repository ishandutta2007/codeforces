#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, S;
	cin >> N >> S;
	if (S >= 2 * N) {
		cout << "YES" << endl;
		for (int i = 0; i < N - 1; ++i) {
			cout << 2 << ' ';
		}
		cout << S - 2 * (N - 1) << endl;
		cout << 1 << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}