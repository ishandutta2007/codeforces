#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, A, CF, CM; long long M;
	cin >> N >> A >> CF >> CM >> M;
	vector<int> a(N), p(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i]; p[i] = i;
	}
	sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });
	vector<int> sa = a;
	sort(sa.begin(), sa.end());
	vector<int> ip(N);
	for (int i = 0; i < N; ++i) ip[p[i]] = i;
	vector<long long> s(N + 1);
	for (int i = 0; i < N; ++i) {
		s[i + 1] = s[i] + a[p[i]];
	}
	long long ret = -1; int seli = -1, selm = -1;
	for (int i = 0; i <= N; ++i) {
		if (1LL * A * (N - i) - (s[N] - s[i]) > M) continue;
		long long rem = M - (1LL * A * (N - i) - (s[N] - s[i]));
		long long l = 0, r = A + 1;
		while (r - l > 1) {
			long long m = (l + r) >> 1;
			int ptr = lower_bound(sa.begin(), sa.end(), m) - sa.begin();
			if (ptr > i) ptr = i;
			long long cons = ptr * m - s[ptr];
			if (cons > rem) r = m;
			else l = m;
		}
		long long cur = 1LL * (N - i) * CF + l * CM;
		if (ret < cur) {
			ret = cur;
			seli = i;
			selm = l;
		}
	}
	cout << ret << '\n';
	for (int i = 0; i < N; ++i) {
		if (i) cout << ' ';
		if (ip[i] >= seli) cout << A;
		else cout << max(a[i], selm);
	}
	cout << '\n';
	return 0;
}