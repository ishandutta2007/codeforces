#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	long long N, M;
	int Q;
	cin >> N >> M >> Q;
	long long g = gcd(N, M);
	for (int i = 0; i < Q; ++i) {
		long long sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey; --sy, --ey;
		long long seps = (sx == 1 ? sy / (N / g) : sy / (M / g));
		long long sepe = (ex == 1 ? ey / (N / g) : ey / (M / g));
		cout << (seps == sepe ? "YES\n" : "NO\n");
	}
	return 0;
}