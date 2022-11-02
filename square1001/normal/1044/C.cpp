#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
	int xl = *min_element(X.begin(), X.end());
	int xr = *max_element(X.begin(), X.end());
	int yl = *min_element(Y.begin(), Y.end());
	int yr = *max_element(Y.begin(), Y.end());
	int A3 = 0;
	for (int i = 0; i < N; ++i) {
		A3 = max(A3, xr + yr - X[i] - Y[i]);
		A3 = max(A3, xr + Y[i] - X[i] - yl);
		A3 = max(A3, X[i] + yr - xl - Y[i]);
		A3 = max(A3, X[i] + Y[i] - xl - yl);
	}
	cout << A3 * 2;
	for (int i = 4; i <= N; ++i) cout << ' ' << (xr + yr - xl - yl) * 2;
	cout << endl;
	return 0;
}