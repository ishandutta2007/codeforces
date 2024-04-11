#include <iostream>
#include <algorithm>
using namespace std;
int N, K, A, B;
int main() {
	cin >> N >> K >> A >> B;
	long long ret = 1LL * A * (N - 1);
	if (K != 1) {
		long long cur = 0;
		while (N != 1) {
			cur += 1LL * A * (N % K) + B;
			N -= N % K;
			N /= K;
			if (N == 0) break;
			ret = min(ret, cur + 1LL * A * (N - 1));
		}
	}
	cout << ret << "\n";
	return 0;
}