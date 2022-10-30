#include <vector>
#include <iostream>
using namespace std;
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main() {
	int N, M;
	cin >> N >> M;
	vector<long long> X(N), P(M);
	for (int i = 0; i < N; ++i) cin >> X[i];
	for (int i = 0; i < M; ++i) cin >> P[i];
	long long g = X[1] - X[0];
	for (int i = 1; i < N; ++i) {
		g = gcd(g, X[i] - X[i - 1]);
	}
	int ans = -1;
	for (int i = 0; i < M; ++i) {
		if (g % P[i] == 0) {
			ans = i;
			break;
		}
	}
	if (ans != -1) {
		cout << "YES" << endl;
		cout << X[0] << ' ' << ans + 1 << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}