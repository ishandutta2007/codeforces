#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> B(N);
	for (int i = 0; i < N; ++i) cin >> B[i];
	int rotate = -1;
	for (int i = 0; i < N; ++i) {
		if (B[(i + N - 1) % N] < B[i]) {
			rotate = i;
			break;
		}
	}
	if (rotate == -1) {
		if (B[0] == 0) {
			cout << "YES\n";
			for (int i = 0; i < N; ++i) {
				if (i) cout << ' ';
				cout << 1;
			}
			cout << '\n';
		}
		else cout << "NO\n";
	}
	else {
		vector<int> RB(N);
		for (int i = 0; i < N; ++i) RB[i] = B[(i + rotate) % N];
		B = RB;
		vector<long long> A(N + 1); A[N] = B[0];
		for (int i = N - 1; i >= 0; --i) {
			if (B[i] > B[(i + N - 1) % N]) A[i] = B[i];
			else A[i] = ((B[(i + N - 1) % N] - B[i]) / A[i + 1] + 1) * A[i + 1] + B[i];
		}
		cout << "YES\n";
		for (int i = 0; i < N; ++i) {
			if (i) cout << ' ';
			cout << A[(i + N - rotate) % N];
		}
		cout << '\n';
	}
	return 0;
}