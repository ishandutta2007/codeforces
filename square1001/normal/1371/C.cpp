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
		long long A, B, N, M;
		cin >> A >> B >> N >> M;
		cout << (A + B >= N + M && min(A, B) >= M ? "Yes" : "No") << endl;
	}
	return 0;
}