#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	long long H; int N;
	cin >> H >> N;
	vector<long long> A(N);
	long long dec = 0, mx = 0;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		dec -= A[i];
		mx = max(mx, dec);
	}
	long long steps = (mx >= H ? 0 : (dec >= 1 ? (H - mx - 1) / dec + 1 : -1));
	if (steps == -1) {
		cout << -1 << '\n';
	}
	else {
		H -= dec * steps;
		int ptr = 0;
		for (int i = 0; i < N && H > 0; ++i) {
			H += A[i];
			++ptr;
		}
		cout << ptr + steps * N << '\n';
	}
	return 0;
}