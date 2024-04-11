#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const long long inf = 1LL << 60;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N; long long A, R, M;
	cin >> N >> A >> R >> M;
	vector<long long> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}
	sort(H.begin(), H.end());
	vector<long long> S(N + 1);
	for (int i = 0; i < N; ++i) {
		S[i + 1] = S[i] + H[i];
	}
	long long ans = inf;
	for (int i = 0; i < N; ++i) {
		long long lc = H[i] * i - S[i];
		long long rc = S[N] - S[i + 1] - H[i] * (N - i - 1);
		ans = min(ans, lc * A + rc * R);
		if (lc >= rc) {
			ans = min(ans, (lc - rc) * A + rc * M);
		}
		else {
			ans = min(ans, (rc - lc) * R + lc * M);
		}
	}
	long long l = H[0], r = H[N - 1] + 1;
	while (r - l > 1) {
		long long m = (l + r) >> 1;
		int ptr = lower_bound(H.begin(), H.end(), m) - H.begin();
		long long lc = m * ptr - S[ptr];
		long long rc = S[N] - S[ptr] - m * (N - ptr);
		if (lc < rc) l = m;
		else r = m;
	}
	int ptrl = lower_bound(H.begin(), H.end(), l) - H.begin();
	long long lcl = l * ptrl - S[ptrl];
	long long rcl = S[N] - S[ptrl] - l * (N - ptrl);
	if (lcl >= rcl) {
		ans = min(ans, (lcl - rcl) * A + rcl * M);
	}
	else {
		ans = min(ans, (rcl - lcl) * R + lcl * M);
	}
	int ptrr = lower_bound(H.begin(), H.end(), r) - H.begin();
	long long lcr = r * ptrr - S[ptrr];
	long long rcr = S[N] - S[ptrr] - r * (N - ptrr);
	if (lcr >= rcr) {
		ans = min(ans, (lcr - rcr) * A + rcr * M);
	}
	else {
		ans = min(ans, (rcr - lcr) * R + lcr * M);
	}
	cout << ans << endl;
	return 0;
}