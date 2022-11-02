#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, M, H;
	cin >> N >> M >> H;
	vector<int> A(N), B(M);
	for (int i = 0; i < M; ++i) cin >> B[i];
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int x;
			cin >> x;
			if (j) cout << ' ';
			cout << (x == 1 ? min(A[i], B[j]) : 0);
		}
		cout << endl;
	}
	return 0;
}