#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	if (M > 2 * N + 2 || M < N - 1) {
		cout << -1 << endl;
		return 0;
	}
	int z = 0;
	if (M > 2 * N) {
		z = M - 2 * N;
		M = 2 * N;
	}
	if (N == M + 1) {
		cout << '0';
		N = M;
	}

	// now N <= M <= 2 * N so we can just print 110110110...101010
	int extra = M - N;
	for (int i = 0; i < extra; ++i)
		cout << "110";
	for (int i = extra; i < N; ++i)
		cout << "10";

	cout << string(z, '1');
	cout << endl;
	return 0;
}