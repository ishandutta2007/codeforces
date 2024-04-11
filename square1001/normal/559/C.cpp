#include <iostream>
#include <algorithm>
using namespace std;
const int modulo = 1000000007;
int H, W, N, x[2009], y[2009], dp[2009], fact[200009], inv[200009], factinv[200009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> H >> W >> N;
	fact[0] = 1, factinv[0] = 1;
	for (int i = 1; i < H + W; ++i) {
		fact[i] = 1LL * fact[i - 1] * i % modulo;
		inv[i] = (i == 1 ? 1 : 1LL * inv[modulo % i] * (modulo - modulo / i) % modulo);
		factinv[i] = 1LL * factinv[i - 1] * inv[i] % modulo;
	}
	x[0] = 1, y[0] = 1;
	for (int i = 1; i <= N; ++i) {
		cin >> x[i] >> y[i];
	}
	x[N + 1] = H, y[N + 1] = W;
	N += 2;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (x[i] < x[j]) {
				swap(x[i], x[j]);
				swap(y[i], y[j]);
			}
			else if (x[i] == x[j] && y[i] < y[j]) {
				swap(y[i], y[j]);
			}
		}
	}
	dp[0] = modulo - 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (x[j] <= x[i] && y[j] <= y[i]) {
				dp[i] = (dp[i] + 1LL * (modulo - 1) * dp[j] % modulo * fact[x[i] - x[j] + y[i] - y[j]] % modulo * factinv[x[i] - x[j]] % modulo * factinv[y[i] - y[j]]) % modulo;
			}
		}
	}
	cout << dp[N - 1] << '\n';
	return 0;
}