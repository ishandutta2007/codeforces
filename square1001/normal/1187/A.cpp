#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int N, S, T;
		cin >> N >> S >> T;
		int R = S + T - N, X = S - R, Y = T - R;
		cout << max(X, Y) + 1 << '\n';
	}
	return 0;
}